/*
1
5 4
0 0
1 2
2 2
4 0
*/
#include<bits/stdc++.h>
using namespace std;

int bishopAttack(int, int);

int main(){
    int t, m, n;

    cin >> t;
    while(t--){
        cin >> m >> n;
        cout << bishopAttack(m, n) << endl;
    }
    return 0;
}

int bishopAttack(int m, int n){
    int arr[m][m], ul[m][m], ur[m][m], c = 0;

    memset(ul, 0, sizeof(ul));
    memset(ur, 0, sizeof(ur));
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                int x = i - 1, y = j - 1;
                while(0 <= x && x < m && 0 <= y && y < m){
                    if(arr[x][y] == 1){
                        ul[i][j] = 1 + ul[x][y];
                        break;
                    }
                    x--;
                    y--;
                }
                x = i - 1;
                y = j + 1;
                while(0 <= x && x < m && 0 <= y && y < m){
                    if(arr[x][y] == 1){
                        ur[i][j] = 1 + ur[x][y];
                        break;
                    }
                    x--;
                    y++;
                }
            }
            c += ur[i][j] + ul[i][j];
            cin.sync();
        }
    }
    return c;
}
