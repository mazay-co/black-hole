#include <iostream>
#include <algorithm>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

class matrix
{
    int **base;
    int size_x, size_y;

public:
    matrix(int c=0,int e=0){
        size_x=e;
        size_y=c;
        base=new int *[size_y];
        for (int i=0; i<size_y; i++){
        base[i] = new int [size_x];
         if (base[i]==0) {cout<<"Не хватает памяти"; exit(1);}
     }}
    ~matrix(){
     for (int i=0; i<size_y; i++)
     delete[] base[i]; delete[] base;
     size_x=0; size_x=0;
     }
    friend ostream & operator <<(ostream & out, matrix & z){
    cout<<"Вывод матрицы:"<<endl;
    for (int c=0; c<z.size_y; c++){
        for (int e=0; e<z.size_x; e++){
    out<<z.base[c][e];
    cout<<" ";}
    cout<<endl;}
    return out;
    }
    friend istream & operator >>(istream & in, matrix & z){
    cout<<"Введите матрицу:"<<endl;
    for (int c=0; c<z.size_y-1; c++){
        for (int e=0; e<z.size_x; e++){
        cout<<"Цепь "<<c+1<<" связана с "<<e+1<<" элементом?"<<endl;
        in>>z.base[c][e];}}
    return in;
    }
    int & elem(int i, int j){return (base[i][j]);}
    int sizex(){return size_x;}
    int sizey(){return size_y;}
};

bool provrazrez (matrix matr, int c, int elem, int i, int platy){
    int s1 = 0, s2 = 0;
        for (int e = i*elem/platy; e < (i+1)*elem/platy;    e++){    s1 = s1 + matr.elem(c, e);}
        for (int e = (i+1)*elem/platy; e < (i+2)*elem/platy; e++){    s2 = s2 + matr.elem(c, e);}
    if ((s1 == 0) || (s2 == 0)) return 1;
    else return 0;
}
void obmen (matrix a, matrix matr, int el, int e, int cp){
    a.elem(cp, 0) = matr.elem(cp, el);
    matr.elem(cp, el) = matr.elem(cp, e);
    matr.elem(cp, e) = a.elem(cp, 0);
}

void func (int elem, int cep, int kolk, int kole, int platy, matrix matr){

    int k0 = 0, mink = elem*elem;
    matrix b(1,elem);
    int k1 = 0;
    bool usl = 1; //индикатор выполнения условия по количеству контактов
            for (int i = 0; i < platy-2; i++){ k1 = 0;
            for (int c=0; c<cep; c++){
                if (provrazrez(matr, c, elem,i, platy) == 0) k1++;
            }
            k0 = k0 + k1; //общее количество контактов в разрезах
            if (k1 <= kolk) usl = usl*1; //выполняется условие
            else usl = usl*0; //не выполняется условие
        }
        if ((usl == 1)&&(k0 < mink)) {
            for (int e = 0; e < elem; e++)
                b.elem(0,e) = matr.elem(cep,e);
                mink = k0;
        }
    int k = 0;
    int k2 = 0;//количество цепей попавших в разрез между двумя платами
    matrix a(cep+1,1);
    for (int el = 0; el < elem; el++){
    for (int e = 0; e < elem; e++){
            if (e != el){
            for (int cp = 0; cp < cep+1; cp++){
                obmen(a, matr, el, e, cp); } //смена элементов

            k=0; //обнуляется счетчик контактов в разрезе
            usl = 1;
            for (int i = 0; i < platy-2; i++){k2 = 0;
                for (int c=0; c<cep; c++){
                    if (provrazrez(matr, c, elem,i, platy) == 0) k2++;
                }
                k = k + k2;

                if (k2 <= kolk) usl = usl*1;
                else usl = usl*0;
            }
            if ((usl == 1)&&(k < mink)) {
            for (int e = 0; e < elem; e++)
                b.elem(0,e) = matr.elem(cep,e);
                mink = k;
            }
    }}}
    if (mink == elem*elem) {
            cout << "Нет вариантов размещения, увеличиваем количество плат на 1 единицу" << endl;
            func(elem, cep, kolk, kole, platy+1, matr);}
    else for (int i = 0; i < platy; i++){
            cout << "Элементы на " << i+1 << " плате ";
            for (int e = i*elem/platy; e < (i+1)*elem/platy;    e++){
                    cout << b.elem(0, e);}
                    cout << endl;}
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int cep = 0, elem = 0;
    cout << "Введите количество цепей" << endl;
    cin >> cep;
    cout << "Введите кол-во элементов" << endl;
    cin >> elem;

    int kole = 0, kolk = 0;
    cout << "Введите количество элементов, помещающихся в блоке" << endl;
    cin >> kole;
    cout << "Введите количество контактов разъема в блоке" << endl;
    cin >> kolk;
    int platy = elem / kole + 1;
    cout << "Требуемое количество плат = " << platy << endl;
    matrix matr(cep+1, elem);
    cin >> matr;
    for (int i = 0; i<elem; i++){matr.elem(cep, i) = i+1;}
    cout << matr;

    func(elem, cep, kolk, kole, platy, matr);
    return 0;
}
