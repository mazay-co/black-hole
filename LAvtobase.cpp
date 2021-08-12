#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
template <class T>
class slew{
   T *base;
   int size;
public:
    slew(int n=0){size=n; base = new T [size];}

    ~slew(){delete[] base; size=0;}

    int resize(){return size;}
    void sets(int k){size=k;}
    T operator [](int i){
     if ((i<0)||(i>size-1)){cout<<"Выход за границу"; exit(1);}
      return base[i];}

    bool  operator ==(const slew &z) {
        bool f = true;
    int k=0;
    if (size!=z.size) { return false;}
    else {for (int i=0; i<size; i++){
        for (int j=0; j<z.size; j++){
        if (base[i]==z.base[j]) k++;
    }}
    if (k!=size) f = false;
    return f;}
    }

    void obed(slew &z){
        int k=0;
     for (int i=0; i<size; i++){ if (z.include(elem(i))) k++;}
       T *a;
       a = new T[size+z.size-k];
     for (int i=0; i<z.size; i++){ a[i]=z.base[i];}
       int t=z.size;
     for (int i=0; i<size; i++){
       if (!(z.include(base[i]))) {a[t]=base[i]; t++;}}
       base=a; size=size+z.size-k;}

    slew & operator =(const slew &z){
      size=z.size;
      base = new T [size];
      for (int i=0; i<size; i++){
        base[i]=z.base[i];}
      return (*this);}

    friend ostream & operator <<(ostream & out, slew & z) {
        cout<<"Машины автобазы"<<endl;
        for (int i=0; i<z.size; i++)
            out<<z.base[i]<<" ";
        cout<<endl;
    return out;}

    void print(){
      for (int i=0; i<size; i++)
       cout<<base[i]<<endl;}

    T &elem(int i){return base[i];}
    void setelem(int i, T h){base[i]=h;}

    void peresech(slew a){
      int k=0;
      for (int i=0; i<size; i++){ if (a.include(elem(i))) k++;}
      if (k==0) cout<<"Нет общих машин"<<endl;
      else{
            T* z;
            int t=0;
      z = new T[k];
      for (int i=0; i<size; i++){
             if (a.include(elem(i))){
             z[t]=base[i]; t++;}}
             base=z; size=k;
      }}

    bool include(T x){

        bool flag=false;
    for (int i=0; i<size; i++){
         if (x==base[i]) flag=true;}
         return flag;}

    void del(){delete[] base; size=0;}

    void add(T h){
        T *z;
        z = new T[size+1];
      for (int i=0; i<size; i++){
             z[i]=base[i]; }
             z[size]=h;
             size++; base=z;}


};

template <class T>
class mnozh: public slew<T>{
    public:
    mnozh(int n=0):slew<T>(n){};
void reshenie(slew<T> *sl, int m){
    int k=0, a;
    slew<T>::print();
        for (int i=0; i<m; i++){
            for (int j=0; j<=i; j++){
            if ((sl[i]==sl[j])&&(i!=j)) {cout<<"Равны автобазы "<<j+1<<" "<<i+1<<endl; a=j+1; k++;}
        }}
        if (k==0) cout<<"Нет равных баз"<<endl;
        else cout<<sl[a-1]<<endl;
    }
};
template <class T>
void mnvo(){
int n, m;
    cout<<"Введите кол-во автобаз"<<endl;
    cin>>m;
    mnozh<T> *sl;
    sl = new mnozh<T> [m];
    //slew<string> *sl0={"КАМАЗ","БЕЛАЗ","ГАЗ-24","ИКАРУС","ЛИАЗ","РАФ"};
    for (int j=0; j<m; j++){
    cout<<"Введите кол-во машин"<<endl;
    cin>>n;
    mnozh<T> mas(n);
    cout<<"Введите машины"<<endl;
    for (int i=0; i<n; i++)
    cin>>mas.elem(i);
    //if (!sl0.include(mas.elem(i)))
    sl[j]=mas;
    }
    char ch;
    while (ch!='e'){
cout<<"Действие:"<<endl;
cout<<"e - Выход                    n - Добавление машины"<<endl;
cout<<"m - Пересечение              p - Объединение"<<endl;
cout<<"r - Присваивание             v - Вхождение машины"<<endl;
cout<<"o - Машина по индексу        d - Удаление"<<endl;
cout<<"f - Размер автобазы          q - Вывод автобазы"<<endl;
cout<<"a - Равенство                x - Проверка одинаковых      Введите символ: ";
cin>>ch;
switch (ch){
    case 'q':{
        cout<<"Введите номер автобазы"<<endl;
        int z; cin>>z;
        cout<<sl[z-1]<<endl; break;}
    case 'n':{
    T h;
    cout<<"Введите номер автобазы в которую требуется добавить"<<endl;
    int z;
    cin>>z;
    cout<<"Введите машину для добавления"<<endl;
    cin>>h;
        if (!sl[z-1].include(h)) sl[z-1].add(h);
        else cout<<"Данная машина уже присутствует"<<endl;
        break;}
    case 'm':{
        int n,m;
        cout<<"Введите номера автобаз для пересечения(запись в первый)"<<endl;
        cin>>n; cin>>m;
        sl[n-1].peresech(sl[m-1]);
        cout<<sl[n-1]<<endl; break;}
    case 'x':{
            (*sl).reshenie(sl, m);
        break;}
    case 'o':{
        int r;
        cout<<"Введите номер автобазы"<<endl;
        int z;
        cin>>z;
        cout<<"Введите индекс искомой машины"<<endl;
        cin>>r;
        if (r<0||r>sl[z-1].resize()) cout<<"Индекс за пределами границ"<<endl;
        else cout<<sl[z-1].elem(r-1)<<endl;
        break;}

    case 'r':{
        int n,m;
        cout<<"Введите номера автобаз для присваивания (запись в первый)"<<endl;
        cin>>n; cin>>m;
    sl[n-1]=sl[m-1];  cout<<sl[n-1]<<endl;
    break;}

    case 'a':{
        int n,m;
        cout<<"Введите номера автобаз для сравнения"<<endl;
        cin>>n; cin>>m;
    if (sl[n-1]==sl[m-1])  cout<<"Автобазы равны"<<endl;
    else cout<<"Автобазы не равны"<<endl;
    break;}

    case 'p':{
        int n,m;
        cout<<"Введите номера автобаз для объединения (запись в первый)"<<endl;
        cin>>n; cin>>m;
    sl[n-1].obed(sl[m-1]);  cout<<sl[n-1]<<endl; break;}

    case 'd':{
        int n;
        cout<<"Введите номер автобазы для удаления"<<endl;
        cin>>n; sl[n-1].del(); cout<<"Автобаза очищена"<<endl;
    break;}
    case 'v':{
        int n;
        cout<<"Введите номер автобазы в котором нужно проверить"<<endl;
        cin>>n;
        T x;
        cout<<"Введите элемент, требующий проверки"<<endl;
        cin>>x;
        if (sl[n-1].include(x)) cout<<"Машина есть в автобазе"<<endl;
        else cout<<"Машинны нет в автобазе"<<endl;
        break;}
    case 'f':{
        int n;
        cout<<"Введите номер автобазы"<<endl;
        cin>>n;
        cout<<"Размерность: "<<sl[n-1].resize()<<endl;
        break;}
    case 'e':{
       exit(0);
       break;}
    default:
       cout<<"Для введеной буквы нет команды в списке"<<endl;
       break;
}}}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //mnvo<int>();
    mnvo<string>();
    return 0;
}

