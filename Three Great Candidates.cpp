#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxProduct(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
        cin >> n;
        cout << maxProduct(n) << endl;
	}
	return 0;
}

bool comp(ll a, ll b){
    return abs(a) < abs(b);
}

ll maxProduct(ll n){
    ll arr[n], count = 0;

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    return max(arr[n - 1] * arr[n - 2] * arr[n - 3], arr[n - 1] * arr[1] * arr[0]);
}
