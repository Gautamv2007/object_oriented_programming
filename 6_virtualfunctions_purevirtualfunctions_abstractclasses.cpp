#include <iostream>
using namespace std;

//A virtual function is a function that is defined in the base class and redefined int the derived class
class Instrument {
public:
    // virtual void MakeSound(){
    //     cout << "Instrument playing..." << endl;
    // }
    virtual void MakeSound() = 0; // This is a pure virtual function
    //Pure virtual function make sure that all derived classes have the above function that we defined

    //This function is a abstract function as there is atleast one pure virtual function
};

class Accordion : public Instrument{
public:
    void MakeSound(){
        cout << "Accordion playing..." << endl;
    }
};

class Piano : public Instrument{
public:
    void MakeSound(){
        cout << "Piano playing..." << endl;
    }
};

int main(void){
    Instrument* i1 = new Accordion();
    // i1->MakeSound();

    Instrument* i2 = new Piano();//This line will give a error if the MakeSound() function is not declared inside the Piano class
    // i2->MakeSound();


    //Making a array of Instrument pointers
    //Using pointers we are able to run the MakeSound() function in one for loop
    Instrument* instruments[2] = {i1, i2};
    for(int i = 0;i<2;i++){
        instruments[i]->MakeSound(); 
    }
}