/*
1
6 24
12 1 61 5 9 2
*/
#include<bits/stdc++.h>
using namespace std;

void subsetSum(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        subsetSum(n, k);
        cout << endl;
    }
    return 0;
}

void subsetSum(int n, int k){
    int arr[n], load[n + 1][k + 1];

    memset(load, 0, sizeof(load));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i <= n; i++)
        load[i][0] = 1;
    for(int i = 1; i <= k; i++)
        load[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            load[i][j] = load[i - 1][j];
            load[i][j] = load[i][j] || load[i - 1][j - arr[i - 1]];
        }
    }
    if(load[n][k] == 0)
        cout << "null";
    else{
        while(1){
            if(k == 0)
                return;
            while(load[n - 1][k] == true){
                n--;
                if(n - 1 < 0)
                    return;
            }
            cout << arr[n - 1] << " ";
            k = k - arr[n - 1];
            n--;
        }
    }
}
