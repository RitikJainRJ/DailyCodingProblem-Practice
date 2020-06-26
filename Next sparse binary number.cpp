#include<bits/stdc++.h>
using namespace std;

int nextSparse(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << nextSparse(n) << endl;
    }
    return 0;
}

int nextSparse(int n){
    string s;
    int res = 0, p = 1, t;

    while(n){
        char x = (n & 1) + '0';
        s = x + s;
        n = n >> 1;
    }
    s = '0' + s;
    for(int i = s.length() - 1; i - 2 >= 0; i--)
        if(s[i] == '1' && s[i - 1] == '1' && s[i - 2] == '0'){
            s[i - 2] = '1', t = i - 1, i = i - 1;
        }
    for(int i = t; i < s.length(); i++)
        s[i] = '0';
    for(int i = s.length() - 1; i >= 0; i--){
        res += p * (s[i] - '0');
        p = p * 2;
    }
    return res;
}
