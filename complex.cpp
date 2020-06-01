#include<iostream>
using namespace std;
 
 class Complex{
     private:
        double corx,cory;
    public:
        Complex(double x=0, double y=0):corx(x), cory(y){};
        void add(Complex added){
            corx+=added.corx;
            cory+=added.cory;
        };
        void show(){
            cout<<corx<<"+"<<cory<<"i"<<endl;
        };
 };

 int main(){
     Complex c1(1,2);
     Complex c2(4.5);
     c1.add(c2);
     c1.show();
     return 0;
 }