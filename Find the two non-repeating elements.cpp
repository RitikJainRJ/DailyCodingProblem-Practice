#include<bits/stdc++.h>
using namespace std;

void findNonRep(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    findNonRep(2 * n + 2);
	    cout << endl;
	}
	return 0;
}

void findNonRep(int n){
    int arr[n], x1, x2, x = 0, y = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    x1 = arr[0];
    for(int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];
    x2 = x1 & ~(x1 - 1);
    for(int i = 0; i < n; i++){
        if(arr[i] & x2)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    if(x < y)
        cout << x << " " << y;
    else
        cout << y << " " << x;
}
