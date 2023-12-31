#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for (int i = 1; i < n; ++i) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}

int main() {
    while (true) {
        string quit;
        cout << "Введите количество цен (или введите 'q' для выхода из программы): ";
        cin >> quit;

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }
        int n = stoi(quit);

        vector<int> prices(n);
        cout << "Введите цены акций: ";
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }

        int result = maxProfit(prices);
        cout << "Максимальная прибыль: " << result << endl;
    }
    return 0;
}