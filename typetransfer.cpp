#include<iostream>
using namespace std;
 
class Stu{
public:
     Stu(int age1):age(age1){}
     Stu(Stu &p):age(p.age){
         cout<<"copy used"<<endl;
     }
     int getAge(){return age;}
private:
     int age;
};

class Room{ //定义班级
public:
    Room(Stu &s1,Stu &s2)
    :s1(s1),s2(s2){}//通过引用的方式，复制构造函数只使用2遍而不是4遍
    Room(Room &l):s1(l.s1),s2(l.s2){}
private:
    Stu s1,s2;
};

void fun(Stu stu1){
    cout<<stu1.getAge()<<endl;
}

int main(){
    Stu xiaoming(10);
    Stu xiaohong(11);
    fun(xiaoming);
    Room grade1(xiaoming,xiaohong);

    return 0;
}

