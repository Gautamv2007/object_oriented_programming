#include <iostream>
#include <unistd.h>     // for usleep()
#include <termios.h>    // for terminal I/O
#include <fcntl.h>      // for fcntl()
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// --------- Non-blocking keyboard handling ----------
int kbhit() {
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}
// ---------------------------------------------------

class Food {
private:
    int x, y;
public:
    Food() { spawn(); }
    void spawn() {
        x = rand() % 20;
        y = rand() % 20;
    }
    int getX() { return x; }
    int getY() { return y; }
};

class Snake {
private:
    int x, y;
    Direction dir;
    vector<pair<int,int>> tail;
    int length;
public:
    Snake(int startX, int startY) {
        x = startX;
        y = startY;
        dir = RIGHT;
        length = 0;
    }
    void setDirection(Direction d) { dir = d; }
    Direction getDirection() { return dir; }
    int getX() { return x; }
    int getY() { return y; }
    vector<pair<int,int>>& getTail() { return tail; }

    void move() {
        if (dir == STOP) return;
        if (length > 0) {
            tail.insert(tail.begin(), {x, y});
            if ((int)tail.size() > length)
                tail.pop_back();
        }
        switch(dir) {
            case LEFT:  x--; break;
            case RIGHT: x++; break;
            case UP:    y--; break;
            case DOWN:  y++; break;
        }
    }

    void grow() { length++; }

    bool checkCollision(int width, int height) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return true;
        for (auto &seg : tail)
            if (seg.first == x && seg.second == y)
                return true;
        return false;
    }
};

class Game {
private:
    bool gameOver;
    int width, height;
    int score;
    Snake snake;
    Food food;

public:
    Game(int w, int h)
        : width(w), height(h), snake(w/2, h/2) {
        gameOver = false;
        score = 0;
    }

    void draw() {
        system("clear"); // Linux clear screen
        for (int i = 0; i < width+2; i++) cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "#";

                if (i == snake.getY() && j == snake.getX())
                    cout << "O";
                else if (i == food.getY() && j == food.getX())
                    cout << "F";
                else {
                    bool print = false;
                    for (auto &seg : snake.getTail()) {
                        if (seg.first == j && seg.second == i) {
                            cout << "o";
                            print = true;
                            break;
                        }
                    }
                    if (!print) cout << " ";
                }

                if (j == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width+2; i++) cout << "#";
        cout << endl;
        cout << "Score: " << score << endl;
    }

    void input() {
        if (kbhit()) {
            switch(getch()) {
                case 'a': snake.setDirection(LEFT); break;
                case 'd': snake.setDirection(RIGHT); break;
                case 'w': snake.setDirection(UP); break;
                case 's': snake.setDirection(DOWN); break;
                case 'x': gameOver = true; break;
            }
        }
    }

    void logic() {
        snake.move();
        if (snake.checkCollision(width, height)) {
            gameOver = true;
            return;
        }
        if (snake.getX() == food.getX() && snake.getY() == food.getY()) {
            score += 10;
            snake.grow();
            food.spawn();
        }
    }

    void run() {
        while (!gameOver) {
            draw();
            input();
            logic();
            usleep(100000); // 100ms delay
        }
        cout << "\nGame Over! Final Score: " << score << endl;
    }
};

int main() {
    srand(time(0));
    Game game(20, 20);
    game.run();
    return 0;
}
