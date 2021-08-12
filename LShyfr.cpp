#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
using namespace std;

string Encode(string input, string keyword)
{
    transform(input.begin(), input.end(), input.begin(), toupper);
    transform(keyword.begin(), keyword.end(), keyword.begin(), toupper);
    //transform_str(input, toupper);
    //transform_str(keyword, toupper);
    input = input.ToUpper();
    keyword = keyword.ToUpper();

    string result = "";

    int keyword_index = 0;

     //void foreach (char symbol)
    //{
        int c = (Array.IndexOf(characters, symbol) +
            Array.IndexOf(characters, keyword[keyword_index])) % N;

        result += characters[c];

        keyword_index++;

        if ((keyword_index + 1) == keyword.Length)
            keyword_index = 0;
    //}

    return result;
}
int main()
{
    char[] characters = new char[] { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И',
                                                'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С',
                                                'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ь', 'Ы', 'Ъ',
                                                'Э', 'Ю', 'Я', ' ', '.', ','};
    string input, keyword;
    cout<<"Введите входной текст"<<endl;
    cin>>input;
    cout<<"Введите ключ"<<endl;
    cin>>keyword;
    cout<<"Получившийся шифр"<<Encode(input,keyword)<<endl;
    return 0;
}
