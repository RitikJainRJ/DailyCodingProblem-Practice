#include<bits/stdc++.h>
using namespace std;

float squareRoot(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << squareRoot(n) << endl;
    }
}

float squareRoot(int n){
    float x = n, y = 1, e = 0.000001;

    while(x - y > e){
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}
