#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll inversion(ll);
ll _inversion(ll[], ll, ll);
ll _merge(ll[], ll, ll);

int main(){
    ll t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << inversion(n) << endl;
    }
    return 0;
}

ll inversion(ll n){
    ll arr[n];

    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    return _inversion(arr, 0, n - 1);
}

ll _inversion(ll arr[], ll l, ll r){
    if(l < r){
        ll m = (l + r) / 2, a, b, c;
        a = _inversion(arr, l, m);
        b = _inversion(arr, m + 1, r);
        c = _merge(arr, l, r);
        return a + b + c;
    }
    return 0;
}

ll _merge(ll arr[], ll l, ll r){
    ll m = (l + r) / 2;
    ll n1 = m - l + 1, n2 = r - m;
    ll temp1[n1], temp2[n2];
    ll i, j, k, res = 0;

    i = 0;
    j = l;
    while(i < n1)
        temp1[i++] = arr[j++];
    i = 0;
    j = m + 1;
    while(i < n2)
        temp2[i++] = arr[j++];
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(temp1[i] <= temp2[j])
            arr[k++] = temp1[i++];
        else{
            res += (m - (l + i) + 1);
            arr[k++] = temp2[j++];
        }
    }
    while(i < n1)
        arr[k++] = temp1[i++];
    while(j < n2)
        arr[k++] = temp2[j++];
    return res;
}
