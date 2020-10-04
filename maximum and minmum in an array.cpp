#include<bits/stdc++.h>
using namespace std;

void solve(int *arr, int n){
    int min_val, max_val;

    if(n % 2)   min_val = max_val = arr[0];
    else{
        if(arr[0] > arr[1])
            min_val = arr[1], max_val = arr[0];
        else
            min_val = arr[0], max_val = arr[1];
    }
    for(int i = n % 2 ? 1 : 2; i < n; i += 2){
        if(arr[i] > arr[i + 1]){
            if(max_val < arr[i])    max_val = arr[i];
            if(min_val > arr[i + 1])    min_val = arr[i + 1];
        }
        else{
            if(max_val < arr[i + 1])    max_val = arr[i + 1];
            if(min_val > arr[i])    min_val = arr[i];
        }
    }
    cout << min_val << " " << max_val;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n);
        cout << endl;
    }
    return 0;
}
