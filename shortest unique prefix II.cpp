#include<bits/stdc++.h>
using namespace std;

void findUniPre(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        findUniPre(n);
        cout << endl;
    }
    return 0;
}

void findUniPre(int n){
    string arr[n];
    bool flag = false;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 1; i < n; i++){
        string A = arr[i - 1], B = arr[i];
        int j;
        for(j = 0; j < min(A.length(), B.length()); j++){
            if(A[j] != B[j])
                break;
        }
        if(!flag){
            flag = true;
            cout << A.substr(0, j + 1) << endl;
        }
        cout << B.substr(0, j + 1) << endl;
    }
}
