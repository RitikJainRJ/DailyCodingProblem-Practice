#include<bits/stdc++.h>
using namespace std;

int minSum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << minSum(n) << endl;
    }
    return 0;
}

int minSum(int n){
    int arr[n], sum = 0, s, res;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    s = sum / 2;
    bool dp[n + 1][s + 1];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= s; j++){
            if(j == 0)  dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else{
                dp[i][j] = dp[i - 1][j];
                if(j - arr[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    for(int i = s; i >= 0; i--){
        if(dp[n][i]){
            res = sum - 2 * i;
            break;
        }
    }
    return res;
}
