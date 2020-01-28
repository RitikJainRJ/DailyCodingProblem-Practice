#include<bits/stdc++.h>
using namespace std;

void nQueen(int);
bool _nQueen(int**, int, int, vector<int>&);
bool isSafe(int**, int, int, int);

int main(){
	int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        nQueen(n);
        cout << endl;
    }
	return 0;
}

void nQueen(int n){
    int **arr = new int*[n];
    vector<int> vec;

    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;
    if(!_nQueen(arr, n, 0, vec))
        cout << -1;
}

bool _nQueen(int **arr, int n, int c, vector<int> &vec){
    if(c == n){
        cout << '[';
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << ']';
        return true;
    }
    bool res = false;
    for(int i = 0; i < n; i++){
        if(isSafe(arr, n, i, c)){
            arr[i][c] = 1;
            vec.push_back(i + 1);
            res = _nQueen(arr, n, c + 1, vec) || res;
            vec.pop_back();
            arr[i][c] = 0;
        }
    }
    return res;
}

bool isSafe(int **arr, int n, int r, int c){
    for(int i = 0; i < c; i++){
        if(arr[r][i] == 1)
            return false;
    }
    int a = r, b = c;
    while(a >= 0 && b >= 0){
        if(arr[a][b] == 1)
            return false;
        a--;
        b--;
    }
    a = r, b = c;
    while(a < n && b >= 0){
        if(arr[a][b] == 1)
            return false;
        ++a;
        --b;
    }
    return true;
}
