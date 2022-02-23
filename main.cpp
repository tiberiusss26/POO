#include <iostream>
#include <cstring>
using namespace std;
define PI 3.14159;
class forma{
    public:
      string form;
      int f,g;
      void afisare(){cout<<"frisca:"<<forma.f<<endl<<"gem:"<<forma.g;}
};
class cerc: public forma{
    int r;
    int h;
    cin>>r>>h;
    g = r*r*PI*h;
    f =

};
class patrat : public forma{
    int l;
    int h;
    cin>>l>>h;
    g = l*l*h;
    f = 6*l*l;
};
class dreptunghi:public forma{

};
class triunghi :public forma{

};
int main() {
    int a, b;
    cin>>a>>b;
}
