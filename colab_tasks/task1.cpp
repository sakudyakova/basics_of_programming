#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* createTree(vector<int>& arr, int index) {
    TreeNode* root = nullptr;

    if (index < arr.size() && arr[index] != -1) {
        root = new TreeNode(arr[index]);
        root->left = createTree(arr, 2 * index + 1);
        root->right = createTree(arr, 2 * index + 2);
    }
    return root;
}
int maxPathSumUtil(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }
    int leftSum = max(0, maxPathSumUtil(root->left, maxSum));
    int rightSum = max(0, maxPathSumUtil(root->right, maxSum));
    maxSum = max(maxSum, leftSum + rightSum + root->val);
    return max(leftSum, rightSum) + root->val;
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}
int main() {
    while (true) {
        string quit;
        cout << "Введите значения для создания бинарного дерева (через пробел) или введите 'q', чтобы выйти из программы: ";
        getline(cin, quit);

        if (quit == "q") {
            cout << "Программа завершена!" << endl;
            break;
        }
        vector<int> arr;
        istringstream ss(quit);
        int x;
        while (ss >> x) {
            arr.push_back(x);
        }
        TreeNode* root = createTree(arr, 0);
        int result = maxPathSum(root);
        cout << "Максимальная сумма путей: " << result << endl;
    }
    return 0;
}