/*
Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.

Формат ввода
Строки состоят из строчных латинских букв, их длина не превосходит 100000. Каждая записана в отдельной строке.

Формат вывода
Выведите "YES" если одна из строк является анаграммой другой и "NO" в противном случае.

Пример 1
Ввод	
dusty
study
Вывод
YES

Пример 2
Ввод	
rat
bat
Вывод
NO
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    if (first.size() != second.size()) cout << "NO" << '\n';
    else {
        map<char, int> f, s;
        for (int i = 0; i < first.size(); ++i) {
            f[first[i]]++;
            s[second[i]]++;
        }
        if (f == s) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}