#include<bits/stdc++.h>
using namespace std;

/*
15
*.*#***#***#.*.
*.*#*.*#.*.#***
***#***#***#*.*
*/

string solve(vector<vector<char>> &mat, int s, int e){
    vector<vector<vector<char>>> characters;
    vector<string> res({"A", "E", "I", "O", "U"});
    vector<vector<char>> temp(3, vector<char>(3));

    characters.push_back({{'.', '*', '.'},
                          {'*', '*', '*'},
                          {'*', '.', '*'}});
    characters.push_back({{'*', '*', '*'},
                          {'*', '*', '.'},
                          {'*', '*', '*'}});
    characters.push_back({{'*', '*', '*'},
                          {'.', '*', '.'},
                          {'*', '*', '*'}});
    characters.push_back({{'*', '*', '*'},
                          {'*', '.', '*'},
                          {'*', '*', '*'}});
    characters.push_back({{'*', '.', '*'},
                          {'*', '.', '*'},
                          {'*', '*', '*'}});
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            temp[i][j] = mat[i][s + j];
    for(int i = 0; i < 5; i++){
        if(characters[i] == temp)
            return res[i];
    }
    return "-";
}

int main(){
    int n;
    string res;

    cin >> n;
    vector<vector<char>> mat(3, vector<char>(n));

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    int i = 0, j;
    for(j = 0; j < n; j++){
        if(mat[0][j] == '#'){
            if(j - i == 3){
                res += solve(mat, i, j - 1) + "*";
            }
            i = j + 1;
        }
    }
    if(j - i == 3)
        res += solve(mat, i, j - 1);
    cout << res << endl;
    return 0;
}
