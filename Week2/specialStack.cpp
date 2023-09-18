#include <iostream>
using namespace std;
class Queue {
public:
    int arr[1000];
    int size = 0;
    Queue(){};
    void enqueue(int x){
        if (size >= 1000) return;
        arr[size] = x;
        size++;
    }
    int dequeue(){
        if (size == 0) return NULL;
        else if (size == 1) {
            int temp = arr[0];
            arr[0] = 0;
            size = 0;
            return temp;
        }
        int temp = arr[0];
        for (int i = 0; i < size; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size] = 0;
        size--;
        return temp;
    }
    bool isEmpty(){
        return !(size > 0);
    }
    void print(){
        for (int i = 0; i < size; i++) cout << arr[i] << ' ';
        cout << endl;
    }
};
void push(Queue &q1, Queue & q2, int n) {
    while (!q2.isEmpty()) {
        int temp = q2.dequeue();
        q1.enqueue(temp);
    }
    q1.enqueue(n);
}
void pop(Queue &q1, Queue &q2) {
    while (!q1.isEmpty()) {
        int temp = q1.dequeue();
        q2.enqueue(temp);
    }
    q2.dequeue();
}
int main(){
    int n;
    cin >> n;
    Queue q1, q2;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        push(q1, q2, temp);
    }
    //q1.print();
    //pop(q1, q2);
    //q2.print();
    cout << tem;
}
