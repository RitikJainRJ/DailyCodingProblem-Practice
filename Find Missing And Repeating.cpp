#include<bits/stdc++.h>
using namespace std;

void findElement(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    findElement(n);
	    cout << endl;
	}
	return 0;
}

void findElement(int n){
    int arr[n], A = 0, B = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        int index = abs(arr[i]) - 1;
        if(arr[index] > 0)
            arr[index] *= -1;
        else
            B = index + 1;
    }
    for(int i = 0; i < n; i++)
        if(arr[i] > 0){
            A = i + 1;
            break;
        }
    cout << B << " " << A;
}
