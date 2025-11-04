#include <iostream>
using namespace std;

class Complex {
    private:
        int Real, Img;
    public:
        Complex(int r = 0, int i = 0){
            Real = r;
            Img = i;
        }

        int real() const {return Real;}
        int img() const {return Img;}

        Complex operator+(const Complex& c) const{
            return Complex(Real + c.Real, Img + c.Img);
        }
};

ostream& operator<<(ostream& COUT, const Complex& c){
    COUT << c.real() << " + " << c.img() <<"i" <<endl;
    return COUT;
}

int main(void){
    Complex c[10];
    for(int i = 0;i<2;i++){
        int a, b;
        cin >> a >> b;
        c[i] = Complex(a, b);
    }
    Complex* c1[10];
    for(int i = 0;i<2;i++){
        int a, b;
        cin >> a >> b;
        c1[i] = new Complex(a, b);
    }

    for(int i = 0;i<2;i++){
        cout << c[i];
    }
    for(int i = 0;i<2;i++){
        cout << *c1[i];
    }
}
