#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        int m = s.length();
        char mat[n][m];

        memset(mat, ' ', sizeof(mat));
        int i = 0, j = 0, k = 0;
        while(j < m){
            while(i < n && j < m){
                mat[i++][j++] = s[k++];
            }
            i -= 2;
            while(i >= 0 && j < m){
                mat[i--][j++] = s[k++];
            }
            i += 2;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cout << mat[i][j];
            cout << endl;
        }
    }
    return 0;
}
