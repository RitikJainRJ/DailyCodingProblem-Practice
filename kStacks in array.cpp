#include<bits/stdc++.h>
using namespace std;

class Kstacks{
private:
    int k, n;
    int *arr;
    int *next;
    int *top;
    int free;

public:
    Kstacks(int k, int n);
    bool isFull() { return (free == -1); }
    void push(int data, int sn);
    bool isEmpty(int sn) { return (top[sn] == -1); }
    int pop(int sn);
};

Kstacks::Kstacks(int k, int n){
    this->k = k;
    this->n = n;
    arr = new int[n];
    next = new int[n];
    top = new int[k];
    free = 0;

    for(int i = 0; i < n - 1; i++)
        next[i] = i + 1;
    next[n - 1] = -1;
    for(int i = 0; i < k; i++)
        top[i] = -1;
}

void Kstacks::push(int data, int sn){
    if(isFull()){
        cout << "Stack is Full" << endl;
        return;
    }
    int index = free;
    free = next[index];

    next[index] = top[sn];
    top[sn] = index;

    arr[index] = data;
}

int Kstacks::pop(int sn){
    if(isEmpty(sn)){
        cout << "Stack is Empty" << endl;
        return INT_MAX;
    }
    int index = top[sn];
    top[sn] = next[index];

    next[index] = free;
    free = index;
    return arr[index];
}

int main(){
    Kstacks ks(3, 10);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << ks.pop(2) << endl;
    cout << ks.pop(1) << endl;
    cout << ks.pop(0) << endl;
    return 0;
}
