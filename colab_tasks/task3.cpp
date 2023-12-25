#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
public:
    MedianFinder() {}
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
    void clear() {
        while (!maxHeap.empty()) maxHeap.pop();
        while (!minHeap.empty()) minHeap.pop();
    }
};

string getNounEnding(int number) {
    int lastDigit = number % 10;
    int lastTwoDigits = number % 100;

    if (lastTwoDigits >= 11 && lastTwoDigits <= 14) {
        return "чисел";
    } else if (lastDigit == 1) {
        return "число";
    } else if (lastDigit >= 2 && lastDigit <= 4) {
        return "числа";
    } else {
        return "чисел";
    }
}

int main() {
    MedianFinder medianFinder;

    while (true) {
        cout << "Введите количество чисел или введите 'q', чтобы выйти из программы: ";
        string quit;
        getline(cin, quit);

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }
        
        istringstream ss(quit);
        int num1;
        ss >> num1;

        cout << "Введите " << num1 << " " << getNounEnding(num1) << " через пробел: ";
        getline(cin, quit);
        istringstream ssNumbers(quit);
        
        int number;
        for (int i = 0; i < num1; ++i) {
            ssNumbers >> number;
            medianFinder.addNum(number);
        }
        double median = medianFinder.findMedian();
        cout << "Медиана: " << median << endl;

        medianFinder.clear();  
    }
    return 0;
}
