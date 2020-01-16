/*
Given a MxN matrix where each element can either be 0 or 1. We need to find the shortest path
between a given source cell to a destination cell. The path can only be created out of a cell if its
value is 1.
*/
#include<bits/stdc++.h>
using namespace std;

int shortPath(int, int);

int main(){
    int t, m, n;

    cin >> t;
    while(t--){
        cin >> m >> n;
        cout << shortPath(m, n) << endl;
    }
}

int shortPath(int m, int n){
    int mat[m][n], dis[m][n];
    int x0, y0, x1, y1;
    int xmove[] = {-1, 0, 0, 1};
    int ymove[] = {0, -1, 1, 0};
    queue<pair<int, int>> q;

    memset(dis, -1, sizeof(dis));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    cin >> x0 >> y0 >> x1 >> y1;
    dis[x0][y0] = 0;
    q.push({x0, y0});
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int tempx = temp.first;
        int tempy = temp.second;
        if(tempx == x1 && tempy == y1){
            return dis[tempx][tempy];
        }
        for(int i = 0; i < 8; i++){
            int _x = tempx + xmove[i];
            int _y = tempy + ymove[i];
            if(0 <= _x && _x < m && 0 <= _y && _y < n){
                if(dis[_x][_y] == -1 && mat[_x][_y] == 1){
                    dis[_x][_y] = dis[tempx][tempy] + 1;
                    q.push({_x, _y});
                }
            }
        }
    }
    return -1;
}
