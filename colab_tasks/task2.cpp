#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs(i - j) <= indexDiff && abs((long long)nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (true) {
        string quit;
        int indexDiff, valueDiff;
        cout << "Введите целочисленный массив (через пробел) или введите 'q', чтобы выйти из программы: ";
        getline(cin, quit);

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }

        vector<int> nums;
        istringstream ss(quit);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        
        cout << "Введите значение indexDiff: ";
        cin >> indexDiff;

        cout << "Введите значение valueDiff: ";
        cin >> valueDiff;

        if (containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}