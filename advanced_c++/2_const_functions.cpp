#include <iostream>
#include <string>
using namespace std;

class Dog {
    int age;
    string name;
public:
    Dog() {age = 3; name = "dummy";}

    //const parameters
    void setAge(const int& a) {
        age = a;
    }

    //const return value
    const string& getName(){
        return name;
    }

    //const function // a const function can only call an another const function
    void printDogName() const {
        cout << name << endl;
    }
};

int main(void){
    Dog d;
    int i = 9;
    d.setAge(i);
    cout << i << endl;
    

    const string& n = d.getName();
    cout << n << endl;
}