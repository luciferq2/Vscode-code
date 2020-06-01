#include<iostream>
using namespace std;



class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){count++;}
    Point(Point &p):x(p.x),y(p.y){count++;}
    ~Point(){count--;}
    int getX(){return x;}
    int getY(){return y;}
    void showCount(){
        cout<<" Object count = "<<count<<endl;
    }
private:
    int x,y;
    static int count;
};

int Point::count=0;

int main(){
    Point a(4,5);
    cout<<a.getX()<<a.getY()<<endl;
    a.showCount();

    Point b(a);
    cout<<b.getX()<<b.getY()<<endl;
    b.showCount();

    {
        Point a(3,3);
        cout<<a.getX()<<a.getY()<<endl;
        a.showCount();
    }

    b.showCount();

    return 0;
}