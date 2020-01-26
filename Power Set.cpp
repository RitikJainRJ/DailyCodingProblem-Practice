#include<bits/stdc++.h>
using namespace std;

void powerSet(string, string, vector<string>&);

int main(){
    int t, n;
    string str, res;

    cin >> t;
    while(t--){
        cin >> n >> str;
        sort(&str[0], &str[0] + str.length());
        vector<string> s;
        powerSet(res, str, s);
        sort(s.begin(), s.end());
        for(auto it = s.begin(); it != s.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}

void powerSet(string res, string str, vector<string> &s){
    if(!res.empty())
        s.push_back(res);
    while(str[0] != '\0'){
        string temp = str;
        temp.erase(0, 1);
        powerSet(res + str[0], temp, s);
        str = temp;
    }
}
