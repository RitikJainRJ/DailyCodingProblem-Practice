#include<bits/stdc++.h>
using namespace std;

int kPalindrome(string, int, int);

int main(){
    int t, n, k;
    string str;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> str;
        cout << kPalindrome(str, n, k) << endl;
    }
    return 0;
}

int kPalindrome(string str, int n, int k){
    int dp[n][n];

    for(int i = 0; i < n; i++)
        dp[i][i] = 0;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2)
                dp[i][j] = (str[i] == str[j]) ? 0 : 1;
            else{
                if(str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    if(dp[0][n - 1] <= k)
        return 1;
    return 0;
}
