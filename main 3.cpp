#include <iostream>
#include <math.h>
using namespace std;
class Numar_Complex {
    double r;
    double i;
public:
    Numar_Complex(const double r_, const double i_){
        r = r_;
        i = i_;
    }
    Numar_Complex(const Numar_Complex &s){
    r = s.r;
    i = s.i;}

    double getR() const {
        return r;
    }

    void setR(double r) {
        Numar_Complex::r = r;
    }

    double getI() const {
        return i;
    }

    void setI(double i) {
        Numar_Complex::i = i;
    }
    void afis(){
        if (r==0){
            if(i==0) cout<<0;
            else cout<<i<<"*i";
        }
        else { cout<<r;
            if (i<0) cout<<i<<"*i";
            if (i>0)  cout<<"+"<<i<<"*i";}
    }
    float modul(){
        return sqrt(r*r+i*i);
    }

    Numar_Complex operator+(const Numar_Complex &rhs) const {
        Numar_Complex nr1(r+rhs.r,i+rhs.i);
        return nr1;
    }
    Numar_Complex operator*(const Numar_Complex &rhs) const {
        Numar_Complex nr1(r*rhs.r-i*rhs.i,r*rhs.i+rhs.r*i);
        return nr1;
    }
    Numar_Complex operator/(const Numar_Complex &rhs) const {
        Numar_Complex nr1((r*rhs.r+i*rhs.i)/(rhs.r*rhs.r+rhs.i*rhs.i),(rhs.r*i-r*rhs.i)/(rhs.r*rhs.r+rhs.i*rhs.i));
        return nr1;
    }

    bool operator==(const Numar_Complex &rhs) const {
        return r == rhs.r &&
               i == rhs.i;
    }



};
int main() {
Numar_Complex n1(10,20);
Numar_Complex n2(n1);
Numar_Complex nn(10,-20);
Numar_Complex n(5,10);
n1.afis();
float mod = n1.modul();
cout<<endl<<mod<<endl;
Numar_Complex n3 = n1 + nn;
n3.afis();
Numar_Complex n4 = n1*n2;
cout<<endl;
n4.afis();
Numar_Complex n5 = n1/n;
cout<<endl;
n5.afis();
    return 0;
}
