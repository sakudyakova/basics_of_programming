#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

int maxHistogramArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int tp;
    int areaWithTop;
    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            tp = s.top();
            s.pop();
            areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);

            if (areaWithTop > maxArea) {
                maxArea = areaWithTop;
            }
        }
    }
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);

        if (areaWithTop > maxArea) {
            maxArea = areaWithTop;
        }
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char> >& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, maxHistogramArea(heights));
    }
    return maxArea;
}

int main() {
    while (true) {
        int rows, cols;
        cout << "Введите количество строк и столбцов матрицы (через пробел) или введите 'q', чтобы выйти из программы: ";
        string quit;
        getline(cin, quit);

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }
        istringstream ss(quit);
        ss >> rows >> cols;

        vector<vector<char> > matrix(rows, vector<char>(cols, '0'));

        cout << "Введите элементы матрицы (построчно, без пробелов):" << endl;
        for (int i = 0; i < rows; i++) {
            string rowInput;
            getline(cin, rowInput);
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rowInput[j];
            }
        }
        int result = maximalRectangle(matrix);
        cout << "Максимальная площадь прямоугольника, содержащего только 1's: " << result << endl;
    }
    return 0;
}