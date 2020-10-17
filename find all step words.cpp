#include<bits/stdc++.h>
using namespace std;

int solve(vector<string> &words, string &word){
    unordered_map<string, int> um;
    int res = 0;

    for(int i = 0; i < words.size(); i++){
        string temp = words[i];
        sort(temp.begin(), temp.end());
        um[temp]++;
    }
    for(char i = 'a'; i <= 'z'; i++){
        string temp = word;
        temp.push_back(i);
        sort(temp.begin(), temp.end());
        res += um[temp];
    }
    return res;
}

int main(){
    int t, n;
    string word;

    cin >> t;
    while(t--){
        cin >> n;
        vector<string> words(n);

        for(int i = 0; i < n; i++)
            cin >> words[i];
        cin >> word;
        cout << solve(words, word) << endl;
    }
    return 0;
}
