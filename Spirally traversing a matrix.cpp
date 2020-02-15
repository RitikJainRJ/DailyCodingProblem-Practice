#include<bits/stdc++.h>
using namespace std;

void spiralMatrix(int, int);

int main(){
    int t, m, n;

    cin >> t;
    while(t--){
        cin >> m >> n;
        spiralMatrix(m, n);
        cout << endl;
    }
    return 0;
}

void spiralMatrix(int m, int n){
    int arr[m][n];
    bool flag;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    int i = 0, j = 0, count = 0;
    while(1){
        flag = false;
        if(count % 4 == 0){
            while(1){
                if(arr[i][j] == -1 || j >= n)
                    break;
                cout << arr[i][j] << " ";
                flag = true;
                arr[i][j] = -1;
                j++;
            }
            i++;
            j--;
        }
        else if(count % 4 == 1){
            while(1){
                if(arr[i][j] == -1 || i >= m)
                    break;
                cout << arr[i][j] << " ";
                flag = true;
                arr[i][j] = -1;
                i++;
            }
            j--;
            i--;
        }
        else if(count % 4 == 2){
            while(1){
                if(arr[i][j] == -1 || j < 0)
                    break;
                cout << arr[i][j] << " ";
                flag = true;
                arr[i][j] = -1;
                j--;
            }
            i--;
            j++;
        }
        else if(count % 4 == 3){
            while(1){
                if(arr[i][j] == -1 || i < 0)
                    break;
                cout << arr[i][j] << " ";
                flag = true;
                arr[i][j] = -1;
                i--;
            }
            i++;
            j++;
        }
        count++;
        if(!flag)
            break;
    }
}
