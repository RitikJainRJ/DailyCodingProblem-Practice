#include<bits/stdc++.h>
using namespace std;

void solve(string&, string&);

int main(){
    int t;
    string s, p;

    cin >> t;
    while(t--){
        cin >> s >> p;
        solve(s, p);
        cout << endl;
    }
    return 0;
}

void solve(string &s, string &p){
    vector<int> res;
    int n = s.length(), m = p.length();
    int hash_s[256] = {0}, hash_p[256] = {0};

    for(int i = 0; i < m; i++)
        hash_p[p[i]]++;
    int i = 0, j, count = 0;
    for(j = 0; j < n; j++){
        hash_s[s[j]]++;

        if(hash_p[s[j]] != 0 && hash_s[s[j]] <= hash_p[s[j]])
            count++;
        if(count == m){
            while(hash_p[s[i]] == 0 || hash_s[s[i]] > hash_p[s[i]]){
                hash_s[s[i]]--;
                i++;
            }
            if(j - i + 1 == m && s.substr(i, m) == p)
                res.push_back(i);
        }
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
