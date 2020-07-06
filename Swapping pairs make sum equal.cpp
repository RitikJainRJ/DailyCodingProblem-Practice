#include<bits/stdc++.h>
using namespace std;

int solve(int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}

int solve(int n, int m){
    int arr1[n], arr2[m];
    int s1 = 0, s2 = 0, d;
    unordered_set<int> us;

    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        s1 += arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
        s2 += arr2[i];
        us.insert(arr2[i]);
    }
    d = (s1 - s2) / 2;
    for(int i = 0; i < n; i++){
        if(us.find(arr1[i] - d) != us.end())
            return 1;
    }
    return -1;
}
