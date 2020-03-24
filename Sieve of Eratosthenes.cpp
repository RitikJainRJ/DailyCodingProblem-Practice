#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(){
	int t, n;
	bool arr[MAX + 1];

	memset(arr, true, sizeof(arr));
	for(int i = 2; i * i <= MAX; i++)
	    if(arr[i] == true)
	        for(int j = i * i; j <= MAX; j = j + i)
	            arr[j] = false;
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i = 2; i <= n; i++)
	        if(arr[i] == true)
	            cout << i << " ";
	    cout << endl;
	}
	return 0;
}
