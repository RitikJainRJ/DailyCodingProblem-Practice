#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class StackHeap{
private:
    pii *arr;
    int n;
    int size;
    int counter;

public:
    StackHeap(int n){
        this->n = n;
        size = 0;
        counter = 0;
        arr = new pii[n];
    }

    void push(int data){
        if(size == n){
            cout << "Full" << endl;
            return;
        }
        size++;
        counter++;
        int i = size - 1;
        arr[i] = {counter, data};

        while(i != 0 && arr[(i - 1) / 2].first < arr[i].first){
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }

    int pop(){
        if(size == 0)
            return -1;
        if(size == 1){
            size--;
            counter--;
            return arr[0].second;
        }
        size--;
        counter--;
        int root = arr[0].second;
        arr[0] = arr[size];
        heapify(0);
        return root;
    }

    void heapify(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;

        if(r < size && arr[l].first < arr[r].first)
            m = r;
        else if(l < size)
            m = l;
        if(arr[i].first < arr[m].first){
            swap(arr[i], arr[m]);
            heapify(m);
        }
    }
};

int main(){
    StackHeap s(5);

    while(1){
        int a, b;
        cin >> a;
        switch(a){
            case 0: cin >> b;
                    s.push(b);
                    break;
            case 1: cout << s.pop() << endl;
                    break;
        }
    }
    return 0;
}
