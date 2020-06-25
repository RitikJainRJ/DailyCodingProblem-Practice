#include<bits/stdc++.h>
using namespace std;

int consecOnes(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << consecOnes(n) << endl;
    }
    return 0;
}

int consecOnes(int n){
    int res = 0, count = 0;

    while(n){
        if(n & 1)
            count++;
        else
            count = 0;
        res = max(res, count);
        n = n >> 1;
    }
    return res;
}
