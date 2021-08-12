#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;
struct person{
char* fio;
double znach;
int r;
person *next;
};

class list{
protected:
  person * h;
  int size;
public:
    list(){size=0; h=0;}
    virtual double optimization(double n) = 0;
    int ret(){return h->r;}
    void add(int q){

person *temp;
temp = new person;
temp->next=h;
h=temp;
temp->fio = new char[30];
cout<<"Введите ФИО:"<<endl;
cin>>temp->fio;
temp->r=q;
cout<<"Введите значение для стажа от 0 до 50, для рейтинга от 0 до 100:"<<endl;
cin>>temp->znach;
if ((temp->znach<0)||(temp->znach>100)) {cout<<"Значение вне границ"<<endl; temp->znach=10;}
}
~list(){release();}

void del(){
person * temp;
temp=h; h=temp->next;
delete temp;
}

void release(){
while (h!=0)
{del();}
}

person * elem(int k){
   person *temp=h;
    for (int i=0; i<k; i++){
        temp=temp->next;
    }
return temp;
}
};
class student: public list{
    public:
    double optimization(double min){
        if (h->znach<min) min=h->znach;
        return min;}
};

class teacher: public list{
    public:
    double optimization(double max){
        if (h->znach>max) max=h->znach;
        return max;}
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, n1, n2;
    double maxm=0, minm=100;

cout<<"Кол-во записей о преподавателях:";
cin>>n1;
cout<<"Кол-во записей о студентах:";
cin>>n2;
n=n1+n2;
 student s[n2];
 teacher p[n1];
  list *sp[n];
 for (int i=0; i<n1; i++){
    cout<<"Данные для преподавателей:"<<endl;
    p[i].add(1);
    sp[i]=&p[i]; }
 for (int i=0; i<n2; i++){
     cout<<"Данные для студeнтов:"<<endl;
    s[i].add(2);
    sp[i+n1]=&s[i]; }
for (int i=0; i<n; i++){
    if (sp[i]->ret()==1)
    maxm=sp[i]->optimization(maxm);
    if (sp[i]->ret()==2)
    minm=sp[i]->optimization(minm);
}
    cout<<"Преподаватель с максимальным стажем:"<<maxm<<endl;
    cout<<"Студент с минимальным рейтингом:"<<minm<<endl;
}
