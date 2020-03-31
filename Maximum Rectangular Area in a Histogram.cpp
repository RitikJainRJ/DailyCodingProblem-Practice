#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll maxAreaHist(ll);

int main(){
	ll t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << maxAreaHist(n) << endl;
	}
	return 0;
}

ll maxAreaHist(ll n){
    ll arr[n], res = 0;
    stack<ll> s;

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    ll i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);
        else{
            ll temp = s.top();
            s.pop();

            ll ans = arr[temp] * (s.empty() ? i : i - s.top() - 1);
            if(ans > res)
                res = ans;
        }
    }
    while(!s.empty()){
        ll temp = s.top();
        s.pop();

        ll ans = arr[temp] * (s.empty() ? i : i - s.top() - 1);
        if(ans > res)
            res = ans;
    }
    return res;
}
