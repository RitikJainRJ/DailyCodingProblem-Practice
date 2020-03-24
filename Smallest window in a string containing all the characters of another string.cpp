#include<bits/stdc++.h>
using namespace std;

string smallestString(string, string);

int main(){
    int t;
    string S, T;

    cin >> t;
    while(t--){
        cin >> S >> T;
        cout << smallestString(S, T) << endl;
    }
    return 0;
}

string smallestString(string S, string T){
    int hash_pat[256] = {0}, hash_str[256] = {0};
    int m = INT_MAX;
    string res;
    bool flag = false;

    for(int i = 0; i < T.length(); i++)
        hash_pat[T[i]]++;
    int i = 0, j, count = 0;
    for(j = 0; j < S.length(); j++){
        hash_str[S[j]]++;

        if(hash_pat[S[j]] != 0 && hash_str[S[j]] <= hash_pat[S[j]])
            count++;
        if(count == T.length()){
            while(hash_str[S[i]] > hash_pat[S[i]] || hash_pat[S[i]] == 0){
                if(hash_str[S[i]] > hash_pat[S[i]])
                    hash_str[S[i]]--;
                i++;
            }
            int len = j - i + 1;
            if(m > len){
                m = len;
                flag = true;
                res = S.substr(i, len);
            }
        }
    }
    if(!flag)
        return "-1";
    return res;
}
