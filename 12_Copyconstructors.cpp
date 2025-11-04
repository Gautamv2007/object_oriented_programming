#include <iostream>
using namespace std;

class Book{
    string Title;
    string Author;
    float* Rates;
    int RatesCounter;
public: 
    Book(string title, string author){
        Title = title;
        Author = author; 

        RatesCounter = 2;
        Rates = new float[RatesCounter];
        Rates[0] = 4;
        Rates[1] = 5;

        cout << Title + " constructor invoked" << endl;
    }
    ~Book(){
        delete [] Rates;
        Rates = nullptr;
        cout << Title + " destructor invoked" << endl;
    }

    //Constructing a copy constructor
    Book(const Book& original){//We are using const so that other users are not able to edit the original object
        Title = original.Title;
        Author = original.Author;
        //Rates = original.Rates; This line will raise error. As when we are making a copy the address is also copied. When the address is initially deleted. The copied object will not have any address to delete. So it will raise an error.
        RatesCounter = original.RatesCounter;

        Rates = new float[RatesCounter];
        for(int i = 0;i<RatesCounter;i++){
            Rates[i] = original.Rates[i];
        }
    }

    friend void PrintBook(Book);
};

void PrintBook(Book book){
    cout << "Title: " << book.Title << endl;
    cout << "Author: " << book.Author << endl;

    float sum = 0;
    for(int i = 0;i<book.RatesCounter;i++){
        sum += book.Rates[i];
    }
    cout <<  "Avg rate: " << sum/book.RatesCounter << endl; 
}

int main(void){
    Book b1("Millionare FastLane", "M. J. DeMarco");
    Book b2("C++ Lambda story", "Bartek Filipek");

    //The above code is an example of copy constructor
    Book b3(b1);
    //Book b3 = b1; This line is also invoking a copy constructor
    //b3 = b2; This line will invoke assignment operator. Assignment operator will be called when we are assigning to a object that is already having some object in it.
    
    PrintBook(b1);
    PrintBook(b2);
    PrintBook(b3);//Here b1 and b3 will be same

}