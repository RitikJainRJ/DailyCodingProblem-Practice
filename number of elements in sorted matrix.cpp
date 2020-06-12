/*
1
5 6
1 3 7 10 15 20
2 6 9 14 22 25
3 8 10 15 25 30
10 11 12 23 30 35
20 25 30 35 40 45
1 1 3 3
*/
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
    int mat[n][m], i1, j1, i2, j2;
    int i, j, a, b, res = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    cin >> i1 >> j1 >> i2 >> j2;
    a = mat[i1][j1];
    b = mat[i2][j2];

    i = 0, j = m - 1;
    while(j >= 0){
        if(mat[i][j] > a || i == n - 1){
            j--;
            res += i;
        }
        else
            i++;
    }
    i = n - 1, j = 0;
    while(j < m){
        if(mat[i][j] < b || i == 0){
            j++;
            res += ((n - 1) - i);
        }
        else
            i--;
    }
    return res - 2;
}
