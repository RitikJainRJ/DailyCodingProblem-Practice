#include<bits/stdc++.h>
using namespace std;

string pairSumDiv(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << pairSumDiv(n) << endl;
	}
	return 0;
}

string pairSumDiv(int n){
    int arr[n], k, sum = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    for(int i = 0; i < n; i += 2){
        sum += arr[i] + arr[i + 1];
        if(sum % k == 0){
            sum = 0;
        }
    }
    return n % 2 || sum ? "False" : "True";
}
