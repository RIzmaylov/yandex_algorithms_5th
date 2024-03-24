/*
Костя успешно прошел собеседование и попал на стажировку в отдел разработки сервиса «Музыка».
Конкретно ему поручили такое задание — научиться подбирать плейлист для группы друзей, родственников или коллег. 
При этом нужно подобрать такой плейлист, в который входят исключительно нравящиеся всем членам группы песни.
Костя очень хотел выполнить это задание быстро и качественно, но у него не получается. Помогите ему написать программу, которая составляет плейлист для группы людей.

Формат ввода
В первой строке расположено одно натуральное число n(1≤n≤2⋅105), где n – количество человек в группе.
В следующих 2⋅n строках идет описание любимых плейлистов членов группы. По 2 строки на каждого участника.
В первой из этих 2-х строк расположено число ki — количество любимых треков i-го члена группы. 
В следующей строке расположено ki строк через пробел — названия любимых треков i-го участника группы.
Каждый трек в плейлисте задан в виде строки, все строки уникальны, сумма длин строк не превосходит 2⋅106. Строки содержат большие и маленькие латинские буквы и цифры.

Формат вывода
Выведите количество, а затем сам список песен через пробел — список треков, которые нравятся каждому участнику группы. 
Ответ необходимо отсортировать в лексикографическом порядке!
Пример 1
Ввод	
1
2
GoGetIt Life
Вывод
2
GoGetIt Life 

Пример 2
Ввод	
2
2
Love Life
2
Life GoodDay
Вывод
1
Life 
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int cnt_ppls = 0;
    cin >> cnt_ppls;
    vector<vector<string>> songs(cnt_ppls);
    for (int i = 0; i < cnt_ppls; ++i) {
        int cnt_songs;
        cin >> cnt_songs;
        vector<string> cur_songs(cnt_songs);
        for (int j = 0; j < cnt_songs; ++j) {
            string song;
            cin >> song;
            cur_songs[j] = song;
        }
        sort(cur_songs.begin(), cur_songs.end());
        songs[i] = cur_songs;
    }
    vector<string> intersections;
    set<string> set_res;
    vector<string> first_vec = songs[0];
    for (int i = 1; i < songs.size(); ++i) {
        intersections.clear();
        set_intersection(songs[i].begin(), songs[i].end(), first_vec.begin(), first_vec.end(), back_inserter(intersections));
        first_vec = intersections;
    }
    // if (intersections.size() == 0) set_res.insert(first_vec.begin(), first_vec.end());
    set_res.insert(first_vec.begin(), first_vec.end());
    cout << set_res.size() << '\n';
    for(const auto& s : set_res) {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}