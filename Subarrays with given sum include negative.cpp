#include<bits/stdc++.h>
using namespace std;

int subSumK(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << subSumK(n) << endl;
    }
    return 0;
}

int subSumK(int n){
    int arr[n], curr = 0, k, res = 0;
    unordered_map<int, vector<int>> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    for(int i = 0; i < n; i++){
        curr += arr[i];
        if(curr == k)
            res++;
        if(um.find(curr - k) != um.end())
            res += um[curr - k].size();
        um[curr].push_back(i);
    }
    return res;
}
