#include<bits/stdc++.h>
using namespace std;

string convert(string&);

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        cout << convert(s) << endl;
    }
}

string convert(string &s){
    string res;
    bool flag = false;

    for(int i = 0; i < s.length(); i++){
        if(i + 1 < s.length() && s[i] == s[i + 1]){
            while(i + 1 < s.length() && s[i] == s[i + 1])
                i++;
            flag = true;
        }
        else
            res += s[i];
    }
    if(flag)
        return convert(res);
    return res;
}
