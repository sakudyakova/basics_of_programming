#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { // левая диагональ
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) { // правая диагональ
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<vector<string> >& res, vector<string>& board, int row, int n) {
    if (row == n) {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(res, board, row+1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> board(n, string(n, '.'));

    solveNQueens(res, board, 0, n);
    return res;
}

int main() {
    while (true) {
        string quit;
        cout << "Введите n (размер доски -  от 1 до 9) или 'q' для выхода из программы: ";
        cin >> quit;

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }
  
        int n = stoi(quit);
        if (n == 2 || n == 3) {
            cout << "Решений нет!" << endl;
            continue;
        }

        if (n < 1 || n > 9) {
            cout << "Неверный размер доски. Введите число от 1 до 9." << endl;
            continue;
        }

        vector<vector<string> > solutions = solveNQueens(n);

        cout << "Различные решения размещения " << n << " ферзей на доске " << n << "x" << n << ": " << endl;
        for (const auto& solution : solutions) {
            for (const auto& row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}