#include<bits/stdc++.h>
using namespace std;

int majorityEle(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << majorityEle(n) << endl;
	}
	return 0;
}

int majorityEle(int n){
    int arr[n], c = 1, index = 0, res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        if(arr[index] == arr[i])
            c++;
        else
            c--;
        if(c == 0){
            c = 1;
            index = i;
        }
    }
    res = arr[index];
    c = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == res)
            c++;
    if(c > n / 2)
        return res;
    return -1;
}
