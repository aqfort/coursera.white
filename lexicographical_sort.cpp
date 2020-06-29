#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void LOWER(string& line) {
    for (auto& letter : line)
        letter = tolower(letter);
}

bool COMPARE(const string &a, const string &b) {
    string x = a, y = b;
    LOWER(x);
    LOWER(y);
    return (x < y);
}

int main() {
    unsigned int number;
    cin >> number;
    vector<string> array(number);
    for (string &item : array)
        cin >> item;
    sort(array.begin(), array.end(), COMPARE);

    // сортируем
    /*sort(begin(array), end(array),
            // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
         [](const string& left, const string& right) {
             // сравниваем лексикографически...
             return lexicographical_compare(
                     // ... все символы строки left ...
                     begin(left), end(left),
                     // ... со всеми символами строки right ...
                     begin(right), end(right),
                     // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
                     [](char cl, char cr) { return tolower(cl) < tolower(cr); }
             );
         }
    );*/

    for (const string &item : array)
        cout << item << ' ';
    return 0;
}