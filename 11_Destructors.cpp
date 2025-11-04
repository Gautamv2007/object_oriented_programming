#include <iostream>
using namespace std;

class Book{
    string Title;
    string Author;
    int* Rates;
    int RateCounter;
public: 
    Book(string title, string author){
        Title = title;
        Author = author; 

        RateCounter = 2;
        Rates = new int[RateCounter];
        Rates[0] = 4;
        Rates[1] = 5;

        cout << Title + " constructor invoked" << endl;
    }
    ~Book(){
        delete [] Rates; // [] symbol must be used to delete all the elements in the array
        Rates = nullptr;
        cout << Title + " destructor invoked" << endl;
    }
};
//For a class without pointers the destructor need not be written manually.
//But when pointers are used our own destructors are needed...
int main(void){
    Book b1("Millionare FastLane", "M. J. DeMarco");
    Book b2("C++ Lambda story", "Bartek Filipek");

    Book b3 = b2;//This line seems to have a problem. Find out what it is?
    

    //The Destructor will be called in the reverse order. That is b2 will be called first and then b1 will be called.

}