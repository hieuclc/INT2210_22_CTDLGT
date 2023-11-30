#include<iostream>
using namespace std;
const int MAX = 1000;
int arr[MAX][MAX];

void init(int n) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            arr[i][j] = 0;
        }
    }
}

int check(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > 1 && i != j) {
                ans += arr[i][j];
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        arr[x][y]++;
    }
    cout << check(n);
}

