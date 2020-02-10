#include<bits/stdc++.h>
using namespace std;

void knightTour(int);
bool _knightTour(int, int, int, int**, int);
bool isSafe(int, int, int**, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        knightTour(n);
    }
    return 0;
}

void knightTour(int n){
    int **arr = new int*[n];
    bool res = false;

    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = -1;
    for(int k = 0; k < n; k++)
        for(int l = 0; l < n; l++){
            arr[k][l] = 0;
            if(_knightTour(k, l, 1, arr, n)){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++)
                        cout << arr[i][j] << "  ";
                    cout << endl;
                }
                res = true;
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    arr[i][j] = -1;
        }
    if(!res)
        cout << -1 << endl;
}

bool _knightTour(int x, int y, int move, int **arr, int n){
    if(move == n * n){
        return true;
    }

    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i = 0; i < 8; i++){
        int _x = x + xMove[i];
        int _y = y + yMove[i];
        if(isSafe(_x, _y, arr, n)){
            arr[_x][_y] = move;
            if(_knightTour(_x, _y, move + 1, arr, n))
                return true;
            arr[_x][_y] = -1;
        }
    }
    return false;
}

bool isSafe(int x, int y, int **arr, int n){
    if(0 <= x && x < n && 0 <= y && y < n && arr[x][y] == -1)
        return true;
    return false;
}
