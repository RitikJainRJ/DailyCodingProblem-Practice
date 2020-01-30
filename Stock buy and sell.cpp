#include<bits/stdc++.h>
using namespace std;

void maxProfit(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
        cin >> n;
        maxProfit(n);
        cout << endl;
	}
	return 0;
}

void maxProfit(int n){
    int arr[n + 1], s = -1, e, flag = 0, flag2 = 0, flag3 = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] <= arr[i + 1]){
            if(flag == 0){
                s = i;
                flag = 1;
            }
            flag2 = 1;
        }
        else{
            if(s == -1 || flag2 == 0)
                continue;
            e = i;
            flag3 = 1;
            cout << "(" << s << " " << e << ") ";
            flag = 0;
            flag2 = 0;
        }
    }
    if(flag3 == 0)
        cout << "No Profit";
}
