#include<bits/stdc++.h>
using namespace std;

void wordPhone(int);
void _wordPhone(string, int[], int, int, unordered_map<int, string>&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        wordPhone(n);
        cout << endl;
    }
    return 0;
}

void wordPhone(int n){
    int arr[n];
    unordered_map<int, string> um;
    string res;

    um[2] = "abc";
    um[3] = "def";
    um[4] = "ghi";
    um[5] = "jkl";
    um[6] = "mno";
    um[7] = "pqrs";
    um[8] = "tuv";
    um[9] = "wxyz";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    _wordPhone(res, arr, n, 0, um);
}

void _wordPhone(string res, int arr[], int n, int level, unordered_map<int, string> &um){
    if(level == n){
        cout << res << " ";
        return;
    }
    string temp = um[arr[level]];
    for(int i = 0; i < temp.size(); i++){
        _wordPhone(res + temp[i], arr, n, level + 1, um);
    }
}
