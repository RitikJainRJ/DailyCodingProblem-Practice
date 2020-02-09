#include<bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000000007
using namespace std;

ll power(ll, ll);

int main(){
    ll t;
    string n, r;

    cin >> t;
    while(t--){
        cin >> n;
        r = n;
        reverse(r.begin(), r.end());
        cout << power(stoi(n), stoi(r)) << endl;
    }
    return 0;
}

ll power(ll n, ll r){
    if(r == 0)
        return 1;
    else if(r == 1)
        return n;
    else{
        ll temp = power(n, r / 2);
        if(r % 2 == 0)
            return ((temp * temp) % MAX);
        else
            return ((n % MAX) * ((temp * temp) % MAX)) % MAX;
    }
}
