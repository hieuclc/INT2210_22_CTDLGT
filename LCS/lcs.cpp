#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> lcs(vector<int> arr1, vector<int> arr2) {
    int m = arr1.size();
    int n = arr2.size();

    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr1[i - 1] == arr2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    stack<int> ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (arr1[i - 1] == arr2[j - 1]) {
            ans.push(arr1[i - 1]);
            i--;
            j--;
        } else if (table[i - 1][j] > table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 10, 3, 4, 5, 6, 7};
    vector<int> arr2 = {2, 3, 4, 6, 7, 9, 10};
    stack<int> ans = lcs(arr1, arr2);
    while (!ans.empty()) {
        int temp = ans.top();
        ans.pop();
        cout << temp << ' ';
    }
    return 0;
}