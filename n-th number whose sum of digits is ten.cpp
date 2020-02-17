#include<bits/stdc++.h>
using namespace std;

int sumTen(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << sumTen(n) << endl;
    }
    return 0;
}

int sumTen(int n){
    int count = 0;

    for(int i = 19; ; i += 9){
        int sum = 0, temp = i;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == 10)
            count++;
        if(count == n)
            return i;
    }
    return -1;
}
