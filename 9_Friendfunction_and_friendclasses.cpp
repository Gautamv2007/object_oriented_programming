#include <iostream>
using namespace std;

class EquilateralTriangle{
    float a;
    float circumference;//We need to make this variable available to the public. But setting it to public or making a public getter function is not the best solution
    float area;// We can use friend keyword to access these private variables
public:
    void setA(float length){
        a = length;
        circumference = 3*a;
        area = (1.73 * a * a) / 4;

    }

    // friend void PrintResults(EquilateralTriangle);
    //When we declare the printresult function inside the class we need to make the class as a homework
    friend class Homework;
};

class Homework{
public:
    void PrintResults(EquilateralTriangle et){
        cout << "circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};

// void PrintResults(EquilateralTriangle et){
//     cout << "circumference = " << et.circumference << endl;
//     cout << "area = " << et.area << endl;
// }

int main(void){
    EquilateralTriangle et;
    et.setA(3);
    Homework h;
    h.PrintResults(et);
    
}