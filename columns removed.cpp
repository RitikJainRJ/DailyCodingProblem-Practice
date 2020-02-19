#include<bits/stdc++.h>
using namespace std;

int columnRemoved(int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << columnRemoved(n, m) << endl;
    }
    return 0;
}

int columnRemoved(int n, int m){
    char arr[n][m];
    int count = 0;

    if(n == 1)
        return 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++)
            if(arr[j][i] < arr[j - 1][i]){
                count++;
                break;
            }
    }
    return count;
}
