#include<bits/stdc++.h>
using namespace std;

int formPalin(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << formPalin(str) << endl;
    }
    return 0;
}

int formPalin(string str){
    int n = str.length();
    int arr[n][n];

    for(int i = 0; i < n; i++)
        arr[i][i] = 0;
    for(int l = 2; l <= n; l++)
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2)
                arr[i][j] = (str[i] == str[j]) ? 0 : 1;
            else if(str[i] == str[j])
                arr[i][j] = arr[i + 1][j - 1];
            else
                arr[i][j] = 1 + min(arr[i][j - 1], arr[i + 1][j]);
        }
    return arr[0][n - 1];
}
