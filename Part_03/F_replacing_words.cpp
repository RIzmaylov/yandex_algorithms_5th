/*
С целью экономии чернил в картридже принтера было принято решение укоротить некоторые слова в тексте. 
Для этого был составлен словарь слов, до которых можно сокращать более длинные слова. 
Слово из текста можно сократить, если в словаре найдется слово, являющееся началом слова из текста. 
Например, если в списке есть слово "лом", то слова из текста "ломбард", "ломоносов" и другие слова, начинающиеся на "лом", 
можно сократить до "лом".

Если слово из текста можно сократить до нескольких слов из словаря, то следует сокращать его до самого короткого слова.

Формат ввода
В первой строке через пробел вводятся слова из словаря, слова состоят из маленьких латинских букв. 
Гарантируется, что словарь не пуст и количество слов в словаре не превышет 1000, а длина слов — 100 символов.

Во второй строке через пробел вводятся слова текста (они также состоят только из маленьких латинских букв). 
Количество слов в тексте не превосходит 105, а суммарное количество букв в них — 106.

Формат вывода
Выведите текст, в котором осуществлены замены.

Пример 1
Ввод	
a b
abdafb basrt casds dsasa a
Вывод
a b casds dsasa a

Пример 2
Ввод	
aa bc aaa
a aa aaa bcd abcd
Вывод
a aa aa bc abcd
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using std::istringstream;

using namespace std;

int main() {
    string dict_str, item;
    map<char, set<string>> dict;
    getline(cin, dict_str);
    istringstream iss(dict_str);
    while(getline(iss, item, ' ')) {
        dict[item[0]].insert(item);
    }

    string words_str;
    vector<string> words;
    getline(cin, words_str);
    istringstream iss2(words_str);
    while(getline(iss2, item, ' ')) {
        auto it = dict.find(item[0]);
        if (it == dict.end()) {
            words.push_back(item);
        } else {
            bool flag = false;
            set<string> :: iterator it_set = (*it).second.begin();
            for (const auto& w : (*it).second) {
                size_t pos = item.find(w);
                if (pos == 0) {
                    flag = true;
                    break;
                }
                it_set++;
            }
            if (flag) words.push_back(*it_set);
            else words.push_back(item);
        }
    }
    for(const auto& w : words) {
        cout << w << ' ';
    }
    cout << endl;
    return 0;
}