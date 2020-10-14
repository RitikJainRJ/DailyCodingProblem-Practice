#include<bits/stdc++.h>
using namespace std;

void solve(char *arr, int n){
    vector<vector<int>> hash(2);
    int res[n], count = 0;

    for(int i = 0; i < n; i++)
        if(arr[i] == '+')
            hash[0].push_back(i);
        else
            hash[1].push_back(i);
    for(int i = 0; i < hash[1].size(); i++)
        res[hash[1][i]] = count++;
    for(int i = 0; i < hash[0].size(); i++)
        res[hash[0][i]] = count++;
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        char arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr, n);
        cout << endl;
    }
    return 0;
}
