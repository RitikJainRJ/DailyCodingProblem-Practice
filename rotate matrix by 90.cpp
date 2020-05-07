#include<bits/stdc++.h>
using namespace std;

void rotMat(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    rotMat(n);
	    cout << endl;
	}
	return 0;
}

void rotMat(int n){
    int arr[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for(int x = 0; x < n / 2; x++){
        for(int y = x; y < n - 1 - x; y++){
            int temp = arr[x][y];

            arr[x][y] = arr[y][n - 1 - x];
            arr[y][n - 1 - x] = arr[n - 1 - x][n - 1 - y];
            arr[n - 1 - x][n - 1 - y] = arr[n - 1 - y][x];
            arr[n - 1 - y][x] = temp;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
}
