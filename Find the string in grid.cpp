#include<bits/stdc++.h>
using namespace std;

void findWord(int, int);
bool _findWord(char**, int, int, int, int, string);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        findWord(n, m);
    }
    return 0;
}

void findWord(int n, int m){
    char **arr = new char*[n];
    string x;
    bool res = false;

    for(int i = 0; i < n; i++)
        arr[i] = new char[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    cin >> x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(x[0] == arr[i][j]){
            if(_findWord(arr, i, j, n, m, x)){
                cout << i << " " << j << ", ";
                res = true;
            }
        }
    if(!res)
        cout << -1 << endl;
    else
        cout << endl;
}

bool _findWord(char **arr, int x, int y, int n, int m, string str){
    int xMove[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int yMove[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for(int i = 0; i < 8; i++){
        int _x = x, _y = y;
        int len = str.length(), temp = 1;

        while(temp < len){
            _x = _x + xMove[i];
            _y = _y + yMove[i];
            if(!(0 <= _x && _x < n && 0 <= _y && _y < m))
                break;
            if(arr[_x][_y] != str[temp])
                break;
            temp++;
        }
        if(temp == len)
            return true;
    }
    return false;
}
