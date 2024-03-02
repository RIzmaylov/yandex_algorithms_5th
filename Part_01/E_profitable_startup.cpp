/*
k  друзей организовали стартап по производству укулеле для кошек. На сегодняшний день прибыль составила n рублей. 
Вы, как главный бухгалтер компании, хотите в каждый из ближайших d дней приписывать по одной цифре в конец числа, выражающего прибыль. 
При этом в каждый из дней прибыль должна делиться на k.
Формат ввода
В единственной строке входных данных через пробел записаны три числа: n,k,d — изначальная прибыль, количество учредителей компании и количество дней, 
которое вы собираетесь следить за прибылью (1≤n,k≤10^9,1≤d≤10^5). НЕ гарантируется, что n делится на k.

Формат вывода
Выведите одно целое число x — прибыль компании через d дней. Первые цифры числа x должны совпадать с числом n. 
Все префиксы числа x, которые длиннее числа n на 1,2,…,d цифр, должны делиться на k. 
Если возможных ответов несколько, выведите любой из них. Если ответа не существует, выведите −1.

Пример 1
Ввод	                Вывод
21 108 1                216

Пример 2
Ввод	                Вывод
5 12 4                  -1

Пример 3
Ввод	                            Вывод
294209208 98069736 69929            Большое число, поэтому вывод через строку

Примечания
В первом тестовом примере всего один день нужно следить за прибылью. Можно дописать цифру 6 в конец числа 21 и получить прибыль, делящуюся на 108.
Во втором тестовом примере мы в первый же день не можем получить прибыль, делящуюся на k, какая бы цифра не была дописана у числу n, поэтому ответа не существует.
*/


#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>

using namespace std;

string CountProfit(uint64_t n_sum, uint64_t k_cnt, uint64_t d_days) {
    uint64_t res = n_sum;
    std::ostringstream oss;
    
    for (uint64_t i = 0; i < d_days; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if ((res * 10 + j) % k_cnt == 0) {
                res = res * 10 + j;
                i++;
                oss << res;
                string s_res = oss.str();
                for (uint64_t k = i; k < d_days; ++k) {
                    s_res.push_back('0');
                }
                return s_res;
            }
        }
    }
    return "-1";
}

int main()
{
    uint64_t n_sum, k_cnt, d_days;
    cin >> n_sum >> k_cnt >> d_days;
    cout << CountProfit(n_sum, k_cnt, d_days) << '\n';
    
    return 0;
}
