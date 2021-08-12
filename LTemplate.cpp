#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

class complex{
double re;
double im;
public:
friend ostream & operator <<(ostream & out, complex & z) {
    out<<" Комп. число:"<<z.re<<"+("<<z.im<<"i)";
    return out;}
friend istream & operator >>(istream & in, complex & z) {
    cout<<"Введите real";
    in>>z.re;
    cout<<"Введите image";
    in>>z.im;
    return in;}
bool  operator ==(const int nom) const;
bool  operator ==(const complex &base) const;
double get_re() const {return re;}
double get_im() const {return im;}
};

bool  complex::operator==(const int nom) const{
   return (get_re()==nom&&get_im()==0);
}
bool  complex::operator==(const complex &base) const{
   return (get_re()==base.get_re()&&get_im()==base.get_im());
}
/*class matrix
{
    int **base;
    int size_x;

public:
    matrix(int a){
        size_x=a;
        base=new int *[size_x];
        for (int i=0; i<size_x; i++){
        base[i] = new int [size_x];
         if (base[i]==0) {cout<<"Не хватает памяти"; exit(1);}
    }}

    ~matrix();
    friend ostream & operator <<(ostream & out, matrix & z){
    cout<<"Вывод матрицы:"<<endl;
    for (int i=0; i<z.size_x; i++){
        for (int j=0; j<z.size_x; j++){
    out<<z.base[i][j];
    cout<<" ";}
    cout<<endl;}
    return out;}
    friend istream & operator >>(istream & in, matrix & z){
    cout<<"Введите матрицу:"<<endl;
    for (int i=0; i<z.size_x; i++){
        for (int j=0; j<z.size_x; j++){
    in>>z.base[i][j];}}
    return in;}
    int & elem(int i, int j){return (base[i][j]);}
};
*/
template <class T>
int nomnul(T m, int n){
    bool flag=true;
    int nom=0;
    int i=0, j=0;
    while (flag&&i<n){
    while (flag&&j<n){
        if (m[i][j]==0) {flag=false; nom=i;}
        //if (m.elem(i,j)==0) {flag=false; nom=i;}
        j++;}
        i++;j=0;}
    if (flag==true) return -1;
    else return nom+1;
}

int nomnul(char **m, int n){
    bool flag=true;
    int nom=0;
    int i=0, j=0;
    while (flag&&i<n){
    while (flag&&j<n){
        if (m[i][j]=='0') {flag=false; nom=i;}
        //if (m.elem(i,j)==0) {flag=false; nom=i;}
        j++;}
        i++;j=0;}
    if (flag==true) return -1;
    else return nom+1;
}
/*
matrix::~matrix(){
for (int i=0; i<size_x; i++)
delete[] base[i];
delete[] base;
size_x=0;
}
*/


int main(int argc, char* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 int n;
 //int **a;
 //float **a;
 //char **a;
complex **a;
 int nom=0;
 cout<<"Введите размерность:";
 cin>>n;

/*a=new int *[n];
        for (int i=0; i<n; i++)
        a[i] = new int [n];*/
/*a=new float *[n];
        for (int i=0; i<n; i++)
        a[i] = new float [n];*/
/*a=new char *[n];
        for (int i=0; i<n; i++)
        a[i] = new char [n];*/
a=new complex *[n];
        for (int i=0; i<n; i++)
        a[i] = new complex [n];

 for (int i=0; i<n; i++)
 for (int j=0; j<n; j++)
    cin>>a[i][j];

 //matrix a(n);
    //cin>>a;
    //cout<<a;
    cout<<"Матрица:"<<endl;
 for (int i=0; i<n; i++){
 for (int j=0; j<n; j++){
    cout<<a[i][j]<<" ";}
    cout<<endl;}

    nom=nomnul(a,n);
    if (nom==-1) cout<<"В матрице нет нулей"<<endl;
    else cout<<"Номер строки с первым нулем: "<<nom;

    for (int i=0; i<n; i++) delete[] a[i];
    delete[] a;
    return 0;
}
