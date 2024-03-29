/*
Домашний питомец мальчика Васи — улитка Петя. Петя обитает на бесконечном в обе стороны вертикальном столбе, который для удобства можно представить как числовую прямую. 
Изначально Петя находится в точке 0.Вася кормит Петю ягодами. У него есть n ягод, каждая в единственном экземпляре. Вася знает, что если утром он даст 
Пете ягоду с номером i, то поев и набравшись сил, за остаток дня Петя поднимется на ai единиц вверх по столбу, но при этом за ночь, потяжелев, съедет на bi единиц вниз. 
Параметры различных ягод могут совпадать.Пете стало интересно, а как оно там, наверху, и Вася взялся ему в этом помочь. Ближайшие n дней он будет кормить 
Петю ягодами из своего запаса таким образом, чтобы максимальная высота, на которой побывал Петя за эти n дней была максимальной. К сожалению, 
Вася не умеет программировать, поэтому он попросил вас о помощи. Найдите, максимальную высоту, на которой Петя сможет побывать за эти n дней и в каком порядке 
Вася должен давать Пете ягоды, чтобы Петя смог её достичь!

Формат ввода
В первой строке входных данных дано число n (1≤n≤5⋅105) — количество ягод у Васи. В последующих n строках описываются параметры каждой ягоды. 
В i+1 строке дано два числа ai и bi (0≤ai,bi≤109) — то, насколько поднимется улитка за день после того, как съест i ягоду и насколько опуститься за ночь.
Формат вывода
В первой строке выходных данных выведите единственное число — максимальную высоту, которую сможет достичь Петя, если Вася будет его кормить оптимальным образом. 
В следующей строке выведите n различных целых чисел от 1 до n — порядок, в котором Вася должен кормить Петю (i число в строке соответствует номеру ягоды, 
которую Вася должен дать Пете в i день чтобы Петя смог достичь максимальной высоты).
Пример 1
Ввод	                Вывод
3                       10
1 5                     2 3 1 
8 2
4 4

Пример 2
Ввод	                Вывод
2                       10
7 6                     2 1 
7 4


Примечания
Во втором примере изначально улитка находится на высоте 0. Пусть сначала Петя накормит её второй ягодой, а затем первой. 
После того как она съест вторую ягоду, за день она поднимется на 7 (и окажется на высоте 7), а за ночь опустится на 4 (и окажется на высоте 3). 
После того как она съест первую ягоду, за день она поднимется на 7 (и окажется на высоте 10), а за ночь опустится на 6 (и окажется на высоте 4).
Таким образом, максимальная высота, на которой побывает улитка при данном порядке кормления, равна 10. 
Нетрудно видеть, что если Петя накормит улитку сначала первой ягодой, а затем второй, то максимальная высота, на которой побывает улитка, будет меньше.

тесты
3
1 5
8 2
4 4

10
2 3 1 
----------
2
7 6
7 4

10
2 1 
----------
5
1 5
8 2
4 4
100 500
10 1

115
5 2 3 4
------------ тест 4
7
160714711 449656269
822889311 446755913
135599877 389312924
480845266 448565595
561330066 605997004
61020590 573085537
715477619 181424399

------------- тест 15
100
111320504 366248673
795507844 954204512
546838875 712009693
290835305 721735267
159760440 816249993
93130607 966307226
595605750 185676190
101163040 327953325
149989495 796807778
873966806 934677835
353505649 542006342
34675204 610858472
944380729 950778206
309415438 788425492
182148581 654353213
488822087 806137988
134394102 247631614
167458327 874682073
883735100 632723121
523938839 979522399
925719726 983206610
350239483 467400369
990607689 211428413
679513171 560686330
28496614 617351072
557631733 568204776
637078930 675645627
226876035 273616448
315777484 500150364
109378997 128408775
257257617 842813570
372938362 689340674
763878605 823076990
81019893 415891345
177707077 851174031
449656269 160714711
798834446 880013416
715477619 181424399
403642447 409974917
129586135 648382742
429014248 477195779
318390928 789081312
522202490 154945342
70663703 607539685
50092962 764820747
399623565 444888018
195282969 722460568
848680263 249403991
439261835 488135242
44558618 509676517
708426597 801141060
592048652 794863955
534003430 754153930
624878749 950548839
650693494 63219754
283079237 285093436
1886864 647773264
975361464 763371317
389312924 135599877
802436733 916523881
5886223 751491209
167794516 598207395
386576826 388597517
201424080 853308909
86335353 893588013
308811749 381966915
294431279 359623093
48946904 641467344
13088544 753246258
205576634 414210634
573085537 61020590
822889311 446755913
100619633 644464578
526473179 802153704
79042330 652683534
216598847 687316171
751365018 759985962
104163021 591339377
46265148 118376683
178280863 287113365
24539167 132508024
492197753 953546232
955828702 989222712
605997004 561330066
479498871 668773827
23215822 116925841
194676444 408180613
619315470 692717061
867977435 395940406
469786584 849551810
161055688 504667277
62190969 830257761
402127003 503811256
480845266 448565595
249519268 512360334
56157847 704502692
786799 229201036
383140962 520723210
655702582 632532642
566237741 569231264
wrong:
6817833413
23 48 55 38 71 89 7 72 43 36 59 19 58 24 84 94 99 83 1 3 4 5 6 8 9 2 11 12 10 14 15 16 17 18 20 21 22 25 26 27 28 29 
30 31 32 33 34 35 37 39 40 41 42 44 45 46 47 49 50 51 52 53 54 56 57 60 61 62 63 64 65 66 67 68 69 70 73 74 75 76 77 
78 79 80 81 82 13 85 86 87 88 90 91 92 93 95 96 97 98 100

right:
6817833413
7 19 23 24 36 38 43 48 55 58 59 71 72 84 89 94 99 83 100 98 97 96 95 93 92 91 90 88 87 86 85 82 81 80 79 78 77 76 75 
74 73 70 69 68 67 66 65 64 63 62 61 60 57 56 54 53 52 51 50 49 47 46 45 44 42 41 40 39 37 35 34 33 32 31 30 29 28 27 
26 25 22 21 20 18 17 16 15 14 13 12 11 10 9 8 6 5 4 3 2 1

-------------тест 16

277086265512
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    int cnt = 0;
    vector<pair<pair<int, int>, int>> berries;
    vector<int> indexes_deg;
    cin >> cnt;
    int step = 1, max_up = 0, idx_of_max = -1;
    while(cnt--) {
        int up, down;
        cin >> up >> down;
        if (up > down) {
            berries.push_back({{up, down}, step++});
        } else {
            if (up > max_up) {
                max_up = up;
                if (idx_of_max != -1) {
                    indexes_deg.push_back(idx_of_max);
                }
                idx_of_max = step++;
            } else {
                indexes_deg.push_back(step++);
            }
        }
        
    }
    sort(berries.begin(), berries.end(), [](const pair<pair<int, int>, int>& left, const pair<pair<int, int>, int>& right) { 
        return left.first.second < right.first.second; });

    int64_t max_hight = 0, sum = 0;
    vector<int> indexes;

    for (int i = 0; i < berries.size(); ++i) {
        if (i == berries.size() - 1) {
            if (idx_of_max == -1) {
                sum += berries[i].first.first;
                if (sum > max_hight) max_hight = sum;
            } else {
                if (max_up > berries[i].first.second) {
                    sum += berries[i].first.first;
                    if (sum > max_hight) max_hight = sum;
                    sum -= berries[i].first.second;
                } else {
                    sum += berries[i].first.first;
                    if (sum > max_hight) max_hight = sum;
                    max_up = 0;
                }
            }
        } else {
            sum += berries[i].first.first;
            if (sum > max_hight) max_hight = sum;
            sum -= berries[i].first.second;
        }
        indexes.push_back(berries[i].second);
    }
    
    if (idx_of_max != -1) {
        sum += max_up;
        if (sum > max_hight) max_hight = sum;
        indexes.push_back(idx_of_max);
    }

    cout << max_hight << '\n';
    for (const auto& idx : indexes) {
        cout << idx << ' ';
    }
    if (!indexes_deg.empty()) {
        for (const auto& idx : indexes_deg) {
            cout << idx << ' ';
        }
        
    }
    
    
    return 0;
}
