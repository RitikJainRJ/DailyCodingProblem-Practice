
#include<bits/stdc++.h>
using namespace std;

void maxGuest(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    maxGuest(n);
	    cout << endl;
	}
	return 0;
}

void maxGuest(int n){
    int in[n], out[n];
    int p = 0, t = 0, c, curr = 0;

    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> out[i];
    c = *max_element(out, out + n);
    int arr[c + 2];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++){
        arr[in[i]]++;
        arr[out[i] + 1]--;
    }
    for(int i = 0; i < c + 2; i++){
        curr += arr[i];
        if(curr > p){
            p = curr;
            t = i;
        }
    }
    cout << p << " " << t;
}
