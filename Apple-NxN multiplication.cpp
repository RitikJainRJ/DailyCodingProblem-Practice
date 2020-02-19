#include<bits/stdc++.h>
using namespace std;

int countX(int, int);

int main(){
    int t, n, x;

    cin >> t;
    while(t--){
        cin >> n >> x;
        cout << countX(n, x) << endl;
    }
    return 0;
}

int countX(int n, int x){
    int count = 0;

    for(int i = 1; i <= n; i++){
        if(i * i < x && x <= i * n && (x % i == 0))
            count += 2;
        if(i * i == x)
            count++;
    }
    return count;
}
