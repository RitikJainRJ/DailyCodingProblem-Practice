/*
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        solve(n, k);
        cout << endl;
    }
    return 0;
}

int solve(int n, int k){
    int arr[n];
    deque<int> dq(k);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++){
        while((!dq.empty()) && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i = k; i < n; i++){
        cout << arr[dq.front()] << " ";
        while((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();
        while((!dq.empty()) && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()];
}
