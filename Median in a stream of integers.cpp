#include<bits/stdc++.h>
#define nan -1
using namespace std;

int main(){
    int n, x;
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;

    cin >> n;
    while(n--){
        int lh, uh;
        cin >> x;
        if(maxheap.empty())
            lh = -1;
        else
            lh = maxheap.top();
        if(minheap.empty())
            uh = -1;
        else
            uh = minheap.top();
        /*
        lh = maxheap.top();
        uh = minheap.top();
        */
        if((lh == -1 && uh == -1) || x < lh)
            maxheap.push(x);
        else
            minheap.push(x);
        if(maxheap.size() == minheap.size() + 2){
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        else if(minheap.size() == maxheap.size() + 2){
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
        if(maxheap.size() == minheap.size()){
            int a, b;
            a = maxheap.top();
            b = minheap.top();
            cout << (float)(a + b) / 2 << endl;
        }
        else if(maxheap.size() > minheap.size())
            cout << maxheap.top() << endl;
        else
            cout << minheap.top() << endl;
    }
    return 0;
}
