#include<bits/stdc++.h>
using namespace std;

void lps(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        lps(str);
        cout << endl;
    }
    return 0;
}

void lps(string str){
    int n = str.length(), m = 0, s = 0, e = 0, flag = 0;
    bool arr[n][n];

    memset(arr, false, sizeof(arr));
    for(int i = 0; i < n; i++)
        arr[i][i] = true;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2){
                if(str[i] == str[j]){
                    arr[i][j] = true;
                    if(flag == 0){
                        m = 2;
                        s = i;
                        e = j;
                        flag = 1;
                    }
                }
            }
            else{
                if(str[i] == str[j] && arr[i + 1][j - 1] == true){
                    arr[i][j] = true;
                    int temp = j - i + 1;
                    if(m < temp){
                        m = temp;
                        s = i;
                        e = j;
                    }
                }
            }
        }
    }
    for(int i = s; i <= e; i++)
        cout << str[i];
}
