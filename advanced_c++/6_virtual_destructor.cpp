#include <iostream>
using namespace std;

class Dog{
public:
    virtual ~Dog(){
        cout << "Dog Destroyed" << endl; 
    }

    
};

class Yellowdog : public Dog{
public:
    ~Yellowdog(){
        cout << "Yellow dog destroyed" << endl;
    }
};

class DogFactory{
public:
    static Dog* createYellowDog(){
        return (new Yellowdog());
    }
};


int main(void){
    Dog* pd = DogFactory::createYellowDog();
    delete pd;
}