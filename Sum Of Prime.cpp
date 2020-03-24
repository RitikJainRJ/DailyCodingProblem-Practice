#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

void sumPrime(int, bool[]);

int main(){
	int t, n;
	bool sieve[MAX + 1];

	memset(sieve, true, sizeof(sieve));
	for(int i = 2; i * i <= MAX; i++)
	    if(sieve[i] == true)
	        for(int j = i * i; j <= MAX; j = j + i)
	            sieve[j] = false;
	cin >> t;
	while(t--){
	    cin >> n;
	    sumPrime(n, sieve);
	    cout << endl;
	}
	return 0;
}

void sumPrime(int n, bool sieve[]){
    bool flag =  false;

    for(int i = 2; i < n; i++){
        if(sieve[i] == true && sieve[n - i] == true && n - i >= 2){
            cout << i << " " << n - i;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << -1;
}
