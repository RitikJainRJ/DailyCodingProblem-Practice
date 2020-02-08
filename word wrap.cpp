#include<bits/stdc++.h>
using namespace std;

void wordWrap(int);
int printSolution(int[], int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        wordWrap(n);
        cout << endl;
    }
    return 0;
}

void wordWrap(int n){
    int arr[n], m;
    int extra[n + 1][n + 1], lc[n + 1][n + 1];
    int c[n + 1], p[n + 1];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            extra[i][j] = (i == j) ? m - arr[j - 1] : extra[i][j - 1] - 1 - arr[j - 1];
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            if(extra[i][j] < 0)
                lc[i][j] = INT_MAX;
            else if(j == n && extra[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extra[i][j] * extra[i][j];
        }
    c[0] = 0;
    for(int j = 1; j <= n; j++){
        c[j] = INT_MAX;
        for(int i = 1; i <= j ; i++){
            if(c[i - 1] != INT_MAX && lc[i][j] != INT_MAX && c[i - 1] + lc[i][j] < c[j]){
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p, n);
}

int printSolution(int p[], int n){
    int k;
    if(p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << p[n] << " " << n << " ";
    return k;
}
