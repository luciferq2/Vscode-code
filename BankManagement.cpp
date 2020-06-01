#include<iostream>
#include<cmath>
using namespace std;

class Saving{
private:
    int id;
    double balance;
    double rate;
    int lastdate;
    double accumulation;
    void record(int date,double amount);
    double accumulate(int date) const{
        return accumulation+balance*(date-lastdate);
    }
public:
    Saving(int date, int id, double rate);
    int getID(){return id;}
    double getBalance(){return balance;}
    double getRate(){return rate;}
    void deposit(int date, double amount);
    void withdrawn(int date, double amount);
    void settle(int date);
    void show();
};

Saving::Saving(int date, int id, double rate)
    :id(id), balance(0), rate(rate), lastdate(date), accumulation(0){
        cout<<date<<"\t#"<<id<<" is created"<<endl;
    }

void Saving::record(int date, double amount){
    accumulation=accumulate(date);
    lastdate=date;
    amount=floor(amount*100+0.5)/100;
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void Saving::deposit(int date, double amount){
    record(date, amount);
}

void Saving::withdrawn(int date, double amount){
    if(amount>getBalance())
        cout<<"Error: not enough money."<<endl;
    else
        record(date, -amount);
}

void Saving::settle(int date){
    double interest=accumulate(date)*rate/365;
    if(interest!=0)
        record(date,interest);
    accumulation=0;
}

void Saving::show(){
    cout<<"#"<<id<<"\t Balance: "<<balance<<endl;
}

int main(){
    Saving sa0(1,2562,0.015);
    Saving sa1(1,1425,0.015);

    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdrawn(60,4000);

    sa0.settle(90);
    sa1.settle(90);
    
    sa0.show();
    sa1.show();

    return 0;
}
