/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a
set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/
#include<bits/stdc++.h>
using namespace std;

void countWays(int, int);
//int _countWays(int, int[], int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        countWays(n, m);
        cout << endl;
    }
    return 0;
}

/*recursion
int _countWays(int n, int arr[], int m){
    if(n == 0){
        return 1;
    }
    else{
        int temp = 0;
        for(int i = 0; i < m; i++){
            if(n - arr[i] >= 0)
                temp += _countWays(n - arr[i], arr, m);
        }
        return temp;
    }
}
*/

void countWays(int n, int m){
    int arr[m], store[n + 1];

    for(int i = 0; i < m; i++)
        cin >> arr[i];
    store[0] = 1;
    for(int i = 1; i <= n; i++){
        int temp = 0;
        for(int j = 0;j < m; j++){
            if(i - arr[j] >= 0)
                temp += store[i - arr[j]];
        }
        store[i] = temp;
    }
    cout << store[n];
    //cout << _countWays(n, arr, m);
}
