#include <iostream>
using namespace std;

void swimUp(int arr[], int n, int i) {
    int parent = (i - 1) / 2;
    if (arr[i] > arr[parent]) {
        swap(arr[i], arr[parent]);
        swimUp(arr, n, parent);
    }
}

void addNode(int arr[], int &n, int data) {
    if (n + 1 >= 1000) return;
    n = n + 1;
    arr[n - 1] = data;
    swimUp(arr, n, n - 1);
}

void sinkDown(int arr[], int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) max = left;
    if (right < n && arr[right] > arr[max]) max = right;
    if (max != i) {
        swap(arr[i], arr[max]);
        sinkDown(arr, n, max);
    }
}

void deleteNode(int arr[], int &n, int data) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == data) {
            index = i;
            n = n - 1;
            break;
        }
    }
    if (index == -1) return;
    swap(arr[index], arr[n]);
    sinkDown(arr, n, index);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {13, 12, 1, 4, 5, 10, 7, 23, 20, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        swimUp(arr, n, i);

    }
    //addNode(arr, n, 6);
    //deleteNode(arr, n, 3);
    print(arr, n);
    return 0;
}
