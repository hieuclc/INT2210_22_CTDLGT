#include <iostream>
using namespace std;
class Stack {
public:
    int arr[1000];
    int size = 0;
    Stack(){};
    void push(int x) {
        if (size >= 1000) return;
        arr[size] = x;
        size++;
    }
    int pop(){
        if (size == 0) return NULL;
        else if (size == 1) {
            int temp = arr[0];
            arr[0] = NULL;
            size = 0;
            return temp;
        }
        int temp = arr[size - 1];
        arr[size - 1] = NULL;
        size--;
        return temp;
    }
    bool isEmpty(){
        return !(size > 0);
    }
    int getSize(){
        return size;
    }
    void print(){
        for (int i = 0; i < size; i++) cout << arr[i] << ' ';
    }
};
void enqueue(Stack& s1, Stack& s2, int n) {
    if (!s2.isEmpty()) {
        while (!s2.isEmpty()) {
            int temp = s2.pop();
            s1.push(temp);
        }
    }
    s1.push(n);
}

int dequeue (Stack &s1, Stack &s2) {
    if (!s1.isEmpty()) {
        while (!s1.isEmpty()) {
            int temp = s1.pop();
            cout << temp << endl;
            s2.push(temp);
        }
    }
    return s2.pop();
}

int main(){
    Stack s1, s2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        enqueue(s1, s2, temp);
    }
    dequeue(s1, s2);
    enqueue (s1, s2, 10);
    s1.print();
    s2.print();
}
