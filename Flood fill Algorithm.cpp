#include<bits/stdc++.h>
using namespace std;

void floodFill(int, int);
void _floodFill(int, int, int**, int, int, int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        floodFill(n, m);
        cout << endl;
    }
    return 0;
}

void floodFill(int n, int m){
    int **arr = new int*[n];
    int x, y, k, c;

    for(int i = 0; i < n; i++)
        arr[i] = new int[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> x >> y >> k;
    c = arr[x][y];
    arr[x][y] = k;
    _floodFill(x, y, arr, n, m, c, k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
}

void _floodFill(int x, int y, int **arr, int n, int m, int c, int k){
    int xMove[] = {-1, 0, 1, 0};
    int yMove[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        int _x = x + xMove[i];
        int _y = y + yMove[i];
        if(0 <= _x && _x < n && 0 <= _y && _y < m && arr[_x][_y] == c){
            arr[_x][_y] = k;
            _floodFill(_x, _y, arr, n, m, c, k);
        }
    }
}
