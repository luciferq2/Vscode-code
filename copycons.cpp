//类的形实结合
//赋值
//返回对象是个类
//以上3种情况下，会调用复制构造函数

#include<iostream>
using namespace std;

class Stu{
public:
    Stu(int code1, int age1, char sex1):code(code1), age(age1), sex(sex1){}
    Stu(Stu &);
    inline void show();
private:
    int code;
    int age;
    char sex;
};

void Stu::show(){
    cout<<"#"<<code<<"Student, age: "<<age<<", sex:"<<sex<<endl;
}

Stu::Stu(Stu &p){
    code=p.code+1;
    age=p.age;
    switch (p.sex)
    {
    case 'M':
        sex='F' ; 
        cout<<"1";
        break;
    case 'F':
        sex='M';
        cout<<"2";
        break;
    default:
        cout<<"The sex info is wrong!"<<endl;
        break;
    }
}

int main(){
    Stu xiaoming(2562,25,'M');
    Stu xiaohong(1425,26,'F');

    Stu xiaohu=xiaoming;

    xiaoming.show();
    xiaohong.show();
    xiaohu.show();
    return 0;
}