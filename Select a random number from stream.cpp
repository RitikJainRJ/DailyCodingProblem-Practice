/*
here we have to select a random number from stream of number.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int n, temp, res;

    cin >> n;
    cin >> res;
    for(int i = 1; i < n; i++){
        cin >> temp;
        int t = rand() % (i + 1);
        if(t == i)
            res = temp;
    }
    cout << res << endl;
    return 0;
}
