#include <iostream>
using namespace std;

//Hiding complex instructions behind simple procedures is called abstraction
//The end user is not aware of the complex work happening behind the scenes

class Smartphone{
public:
    virtual void TakeASelfie() = 0; // This is now a abstract classes
    //We cannot create instances of an abstract classes
    //But we can make pointers of this class
    virtual void MakeACall() = 0;
};

class Android : public Smartphone{
public:
    void TakeASelfie(){
        cout << "Android Selfie" << endl;
    }
    void MakeACall(){
        cout << "Android calling" << endl;
    }
};

class Iphone: public Smartphone{
public:
    void TakeASelfie(){
        cout << "Iphone selfie" << endl;
    }
    void MakeACall(){
        cout << "Iphone calling" << endl;
    }
};

int main(){
    Smartphone* s1 = new Android();
    Smartphone* s2 = new Iphone();
    s1->TakeASelfie();
    s2->MakeACall();
    //Now by using abstraction we are calling all developers who are using "Smartphone" class to implement the following functionality
    //We can use those functionality without knowing about the complex details which are hidden
}
