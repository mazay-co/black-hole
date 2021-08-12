#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct sport{
char *fio;
int rost;
sport *next;
};

class list{
sport *h;
int size;
public:
  list(){size=0; h=0;}
  ~list(){release();}
  void add();
  void del();
  void print();
  void release();
  sport * elem(int i);
  char * max_rost(int n);
  };

void list::add(){
sport *temp;
temp = new sport;
temp->next=h;
h=temp;
temp->fio = new char[30];
cout<<"������� ���:"<<endl;
cin>>temp->fio;
cout<<"������� ����:"<<endl;
cin>>temp->rost;
if (temp->rost<0) {
    cout<<"������������ �������� �����"<<endl;
    temp->rost=150;
}

}

void list::del(){
sport * temp;
temp=h;
h=temp->next;
delete temp;
}



void list::print(){
sport *temp;
temp=h;
while (temp!=0)
{ cout<<temp->fio<<" ����:"<<temp->rost<<endl;
temp=temp->next;}
}

void list::release(){
while (h!=0)
{del();}
}

sport * list::elem(int k){
   sport *temp=h;
    for (int i=0; i<k; i++){
        temp=temp->next;
    }
return temp;
}

char * list::max_rost(int n){
sport *maxr=h;
for (int i=0; i<n; i++){

if (elem(i)->rost>maxr->rost){
    maxr->rost=elem(i)->rost;
    maxr->fio=elem(i)->fio;}

/*if ((elem(i)->rost)==(maxr->rost)){
    cout<<"����. ���� "<<elem(i)->rost<<" � ";
    return (elem(i)->fio);
    cout<<" � "<<endl;}*/
}
    cout<<"����. ���� "<<maxr->rost<<" � ";
    return (maxr->fio);
    cout<<endl;
}



int main(int argc, char* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 list sp;
 int n;
 cout<<"���-�� �������:";
 cin>>n;
 for (int i=0; i<n; i++)
 sp.add();
 sp.print();
 cout<<sp.max_rost(n);

    return 0;
}
