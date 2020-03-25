#include<bits/stdc++.h>
using namespace std;

int countOccurence(string, string);

int main(){
	int t;
	string S, C;

	cin >> t;
	while(t--){
	    cin >> S >> C;
	    cout << countOccurence(S, C) << endl;
	}
	return 0;
}

int countOccurence(string S, string C){
    int hash_pat[256] = {0}, hash_str[256] = {0};
    int n = S.length(), m = C.length(), res = 0;

    for(int i = 0; i < m; i++)
        hash_pat[C[i]]++;
    int i = 0, j, count = 0;
    for(j = 0; j < n; j++){
        hash_str[S[j]]++;

        if(hash_pat[S[j]] != 0 && hash_str[S[j]] <= hash_pat[S[j]])
            count++;
        if(count == m){
            while(hash_pat[S[i]] == 0 || hash_str[S[i]] > hash_pat[S[i]]){
                if(hash_str[S[i]] > hash_pat[S[i]])
                    hash_str[S[i]]--;
                i++;
            }
            int len = j - i + 1;
            if(len == m)
                res++;
        }
    }
    return res;
}


