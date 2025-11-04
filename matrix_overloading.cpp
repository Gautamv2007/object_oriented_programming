#include <iostream>
using namespace std;

class Matrix{
private:
    int row, col;
    int **data;
public:
    Matrix(int r, int c) : row(r), col(c){
        data = new int*[row];
        for(int i = 0;i<r;i++){
            data[i] = new int[col];
        }
    }

    friend istream& operator>>(istream& in, Matrix& m){
        for(int i = 0;i<m.row;i++){
            for(int j = 0;j<m.col;j++){
                in >> m.data[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Matrix &m){
        for(int i = 0;i<m.row;i++){
            for(int j = 0;j<m.col;j++){
                out << m.data[i][j] << " ";
            }
            cout << endl;
        }
        return out;
    }

    Matrix operator+(Matrix const &m){
        Matrix temp(m.row, m.col);
        for(int i = 0;i<m.row;i++){
            for(int j = 0;j<m.col;j++){
                temp.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return temp;
    }

    Matrix operator*(Matrix const &m){
        Matrix temp(row, m.col);
        for(int i = 0;i<row;i++){
            for(int j = 0;j<m.col;j++){
                int s = 0;
                for(int k = 0;k<m.row;k++){
                    temp.data[i][j] += data[i][j] * m.data[j][k];
                }
            }
        }
        return temp;
    }
    Matrix transpose(){
        Matrix temp(col, row);
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                temp.data[i][j] = data[j][i];
            }
        }
        return temp;
    }

};


int main(void){
    Matrix a(2, 2);
    Matrix b(2, 2);
    cin >> a;
    Matrix c = a.transpose();
    cout << c;
}