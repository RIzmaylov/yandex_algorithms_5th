/*
Вася решил заняться торговлей рыбой. С помощью методов машинного обучения он предсказал цены на рыбу на N дней вперёд. 
Он решил, что в один день он купит рыбу, а в один из следующих дней — продаст 
(то есть совершит или ровно одну покупку и продажу или вообще не совершит покупок и продаж, 
если это не принесёт ему прибыли). К сожалению, рыба — товар скоропортящийся и разница между номером дня 
продажи и номером дня покупки не должна превышать K.

Определите, какую максимальную прибыль получит Вася.

Формат ввода
В первой строке входных данных задаются числа N и K (1 ≤ N ≤ 10000, 1 ≤ K ≤ 100).

Во второй строке задаются цены на рыбу в каждый из N дней. 
Цена — целое число, которое может находится в пределах от 1 до 109.

Формат вывода
Выведите одно число — максимальную прибыль, которую получит Вася.

Пример 1
Ввод	            Вывод
5 2                 2
1 2 3 4 5
Пример 2
Ввод	            Вывод
5 2                 0
5 4 3 2 1

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, minPrice;
    cin >> N >> K;
    vector<int> indexOfMinPrices{0};
    vector<int> allPrices;

    while(N--) {
        int price;
        cin >> price;
        allPrices.push_back(price);
    }
    minPrice = allPrices[0];

    for(int i = 1; i < allPrices.size() - 1; i++) {
        if (allPrices[i] < minPrice) {
            minPrice = allPrices[i];
            indexOfMinPrices.clear();
            indexOfMinPrices.push_back(i);
        } else if (allPrices[i] == minPrice) {
            indexOfMinPrices.push_back(i);
        }
    }
    int profit = 0;
    for (int i = 0; i < indexOfMinPrices.size(); i++) {
        int maxPrice = allPrices[indexOfMinPrices[i] + 1];
        profit = max(profit, maxPrice - allPrices[indexOfMinPrices[i]]);
        for (int j = indexOfMinPrices[i] + 1; j <= K + indexOfMinPrices[i] && j < allPrices.size(); ++j) {
            if (allPrices[j] > maxPrice) {
                maxPrice = allPrices[j];
                profit = max(profit, maxPrice - allPrices[indexOfMinPrices[i]]);
            }
        }
    }
    cout << profit << '\n';
    return 0;
}