#include<bits/stdc++.h>
using namespace std;

int minSquare(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minSquare(n) << endl;
	}
	return 0;
}

int minSquare(int n){
    int arr[n + 1];

    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++){
        int m = INT_MAX;
        for(int j = 1; j * j <= i; j++)
            m = min(m, 1 + arr[i - j * j]);
        arr[i] = m;
    }
    return arr[n];
}
