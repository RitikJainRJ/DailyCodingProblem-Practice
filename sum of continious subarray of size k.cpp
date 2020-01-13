#include<bits/stdc++.h>
using namespace std;

void solve(int, int);

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

void solve(int n, int k){
    int arr[n], store[n], sum = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < k; i++)
        sum += arr[i];
    store[k - 1] = sum;
    cout << store[k - 1] << " ";
    for(int i = k; i < n; i++){
        store[i] = store[i - 1] + arr[i] - arr[i - k];
        cout << store[i] << " ";
    }
}

