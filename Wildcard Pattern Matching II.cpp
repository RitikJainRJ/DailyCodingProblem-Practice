#include<bits/stdc++.h>
using namespace std;

int wildcardMatch(string, string);

int main(){
    int t;
    string pat, str;

    cin >> t;
    while(t--){
        cin >> pat >> str;
        cout << wildcardMatch(pat, str) << endl;
    }
    return 0;
}

int wildcardMatch(string pat, string str){
    int i = 0, n, m;

    while(pat[i] != '\0'){
        if(pat[i] == '*' && pat[i + 1] == '*')
            pat.erase(i + 1, 1);
        else
            i++;
    }
    n = str.length();
    m = pat.length();
    bool arr[n + 1][m + 1];
    memset(arr, false, sizeof(arr));
    arr[0][0] = true;
    for(int i = 1; i <= m; i++)
        if(pat[i - 1] == '*')
            arr[0][i] = arr[0][i - 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            if((str[i - 1] == pat[j - 1]) || (pat[j - 1] == '?'))
                arr[i][j] = arr[i - 1][j - 1];
            else if(pat[j - 1] == '*')
                arr[i][j] = arr[i - 1][j] || arr[i][j - 1];
            else
                arr[i][j] = false;
        }
    }
    return arr[n][m];
}
