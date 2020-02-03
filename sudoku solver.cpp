#include<bits/stdc++.h>
#define N 9
using namespace std;

bool isSafe(int arr[N][N], int row, int col, int x){
    for(int i = 0; i < N; i++)
        if(arr[row][i] == x)
            return false;
    for(int i = 0; i < N; i++)
        if(arr[i][col] == x)
            return false;
    int r = row - (row % 3);
    int c = col - (col % 3);
    for(int i = r; i < r + 3; i++)
        for(int j = c; j < c + 3; j++)
            if(arr[i][j] == x)
                return false;
    return true;
}

bool sudokuSolver(int arr[N][N]){
    int row, col, flag = 0;
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if(arr[row][col] == 0){
                flag = 1;
                break;
            }
    if(flag == 0)
        return true;
    for(int i = 1; i <= N; i++){
        if(isSafe(arr, row, col, i)){
            arr[row][col] = i;
            if(sudokuSolver(arr))
                return true;
            arr[row][col] = 0;
        }
    }
    return true;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int arr[N][N];

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> arr[i][j];
        sudokuSolver(arr);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
