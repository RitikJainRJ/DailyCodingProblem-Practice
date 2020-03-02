#include<bits/stdc++.h>
using namespace std;

int numIsland(int, int);
void _numIsland(int**, int, int, int, int);
bool isSafe(int, int, int**, int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << numIsland(n, m) << endl;
    }
    return 0;
}

int numIsland(int n, int m){
    int count = 0;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j] == 1){
                count++;
                _numIsland(arr, i, j, n, m);
            }
    return count;
}

void _numIsland(int **arr, int x, int y, int n, int m){
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    arr[x][y] = -1;
    for(int i = 0; i < 8; i++){
        int _x = x + xMove[i];
        int _y = y + yMove[i];
        if(isSafe(_x, _y, arr, n, m)){
            _numIsland(arr, _x, _y, n, m);
        }
    }
}

bool isSafe(int x, int y, int **arr, int n, int m){
    if(0 <= x && x < n && 0 <= y && y < m && arr[x][y] == 1)
        return true;
    return false;
}
