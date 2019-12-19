/*
https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n, pi, ic = 0, is = 0;

    srand(time(0));
    cin >> n;
    for(int i = 0; i < 10000; i++){
        double x = double(rand() % int(10000 + 1)) / 10000;
        double y = double(rand() % int(10000 + 1)) / 10000;

        double res = x * x + y * y;
        if(res <= 1)
            ic++;
        is++;
    }
    pi = double(4 * ic) / is;
    cout << pi << endl;
    return 0;
}
