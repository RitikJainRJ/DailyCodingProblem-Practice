#include<bits/stdc++.h>
using namespace std;

int wildcardMatch(string, string);
int _wcm(int, int, string, string, map<pair<int, int>, bool>&);

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
    map<pair<int, int>, bool> um;

    return _wcm(pat.length() - 1, str.length() - 1, pat, str, um);
}

int _wcm(int m, int n, string pat, string str, map<pair<int, int>, bool> &um){
    if(m == -1 && n == -1)
        return 1;
    if(m == -1)
        return 0;
    if(n == -1){
        if(pat[0] == '*')
            return 1;
        return 0;
    }
    if(pat[m] != '*' && pat[m] != '?'){
        if(pat[m] == str[n]){
            if(um.find({m, n}) == um.end())
                um[{m, n}] = _wcm(m - 1, n - 1, pat, str, um);
            return um[{m, n}];
        }
        else
            return 0;
    }
    if(pat[m] == '?'){
        if(um.find({m, n}) == um.end())
            um[{m, n}] = _wcm(m - 1, n - 1, pat, str, um);
        return um[{m, n}];
    }
    if(pat[m] == '*'){
        int temp = 0;
        for(int i = 0; n - i >= -1; i++){
            if(um.find({m, n}) == um.end())
                um[{m, n}] = _wcm(m - 1, n - i, pat, str, um);
            temp = um[{m, n}];
            if(temp == 1)
                break;
        }
        return temp;
    }
}
