#include <iostream>
using namespace std;


class Complex{
private:
    int real, img;
public:
    Complex(int a = 0 , int b = 0) : real(a), img(b){};
    Complex operator+(Complex const &c){
        return Complex(real + c.real, img + c.img);
    }

    friend ostream& operator<<(ostream& out, Complex const &c){
        out << c.real << " + " << c.img << "i";
        return out;
    }

    Complex operator-(Complex const &c){
        return Complex(real - c.real, img - c.img);
    }

    friend istream& operator>>(istream& in, Complex &c){
        in >> c.real >> c.img;
        return in;
    }

    Complex operator*(Complex const &c){
        Complex temp;
        temp.real = real * c.real -  img * c.img;
        temp.img = img * c.real + real * c.img;
        return temp;
    }
};

int main(void){
    Complex a, b;
    cin >> a >> b;
    Complex c;
    c = a * b;
    cout << c;
}