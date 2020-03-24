bool isSafe(int x, int y, char **arr, int n, int m, string B, int index){
    if(0 <= x && x < n && 0 <= y && y < m && arr[x][y] == B[index])
        return true;
    return false;
}

bool findWord(char **arr, int x, int y, int n, int m, string B, int index){
    if(index == B.length())
        return true;
    int xMove[] = {0, -1, 0, 1};
    int yMove[] = {-1, 0, 1, 0};
    bool res =  false;

    for(int i = 0; i < 4; i++){
        int _x = x + xMove[i];
        int _y = y + yMove[i];
        if(isSafe(_x, _y, arr, n, m, B, index)){
            res = res || findWord(arr, _x, _y, n, m, B, index + 1);
        }
    }
    return res;
}


int Solution::exist(vector<string> &A, string B){
    int n = A.size(),  m = A[0].length();
    char **arr = new char*[n];

    for(int i = 0; i < n; i++)
        arr[i] = new char[m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            arr[i][j] = A[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == B[0] && findWord(arr, i, j, n, m, B, 1)){
                return 1;
            }
        }
    }
    return 0;
}
