/*
1
10
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/
#include<bits/stdc++.h>
using namespace std;

void conwaysGame(int);
bool isSafe(int, int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        conwaysGame(n);
        cout << endl;
    }
    return 0;
}

void conwaysGame(int n){
    int arr[n][n], load[n][n];
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            load[i][j] = arr[i][j];
        }
    int hi = 5;
    while(1){
        int flag = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int _x = i + xMove[k];
                    int _y = j + yMove[k];
                    if(isSafe(_x, _y, n) && arr[_x][_y] == 1)
                        count++;
                }
                if(arr[i][j] == 1 && count < 2)
                    load[i][j] = 0, flag = 1;
                else if(arr[i][j] == 1 && count > 3)
                    load[i][j] = 0, flag = 1;
                else if(arr[i][j] == 0 && count == 3)
                    load[i][j] = 1, flag = 1;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                arr[i][j] = load[i][j];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char ch = (arr[i][j] == 1) ? '*' : '.';
                cout << ch << " ";
            }
            cout << endl;
        }
        cout << "++++++++++++++\n";
        if(flag == 0)
            break;
    }
}

bool isSafe(int x, int y, int n){
    if(0 <= x && x < n && 0 <= y && y < n)
        return true;
    return false;
}
