#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 1; i < n; i++)
            arr[i] = arr[i - 1] ^ arr[i];
        cout << arr[n - 1] << endl;
    }
    return 0;
}
