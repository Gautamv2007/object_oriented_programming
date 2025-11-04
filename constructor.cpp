#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    Student(string n, int a){
        name = n;
        age = a;
        cout << "Constructor called for " << name << endl;
    }
    ~Student(){
        cout << "Destructor called for" << name << endl;
    }
};