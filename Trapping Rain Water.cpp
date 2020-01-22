#include<bits/stdc++.h>
using namespace std;

int waterTrapped(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << waterTrapped(n) << endl;
    }
    return 0;
}

int waterTrapped(int n){
    int arr[n], load1[n], load2[n], sum = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    load1[0] = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > load1[i - 1] + arr[i - 1])
            load1[i] = 0;
        else
            load1[i] = load1[i - 1] + arr[i - 1] - arr[i];
    }
    load2[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > load2[i + 1] + arr[i + 1])
            load2[i] = 0;
        else
            load2[i] = load2[i + 1] + arr[i + 1] - arr[i];
    }
    for(int i = 0; i < n; i++)
        load1[i] = min(load1[i], load2[i]);
    for(int i = 0; i < n; i++)
        sum += load1[i];
    return sum;
}
