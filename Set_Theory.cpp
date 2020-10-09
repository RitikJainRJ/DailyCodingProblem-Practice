#include<bits/stdc++.h>
using namespace std;

int main(){
    int p1, p2, p3, q, e, r;
    int k, res1, res2;

    cin >> p1 >> p2 >> p3 >> q >> e >> r;
    k = (e - r - p1 - p2 - p3 + 2 * q) / 3;
    res1 = k + p1 + p3 - q;
    res2 = k * 3;
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}
