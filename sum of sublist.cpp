#include<bits/stdc++.h>
using namespace std;

void sumSublist(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        sumSublist(n);
        cout << endl;
    }
    return 0;
}

void sumSublist(int n){
    int arr[n], s, e;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    cin >> s >> e;
    cout << arr[e - 1] - arr[s - 1];
}
