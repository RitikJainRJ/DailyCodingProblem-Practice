/*
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house
with kth color, return the minimum cost which achieves this goal.
*/
#include<bits/stdc++.h>
using namespace std;

int minCost(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << minCost(n, k) << endl;
    }
    return 0;
}

int minCost(int n, int k){
    int arr[n][k];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
            cin >> arr[i][j];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < k; j++){
            int min = INT_MAX;
            for(int l = 0; l < k; l++){
                if(l == j)
                    continue;
                if(min > arr[i - 1][l])
                    min = arr[i - 1][l];
            }
            arr[i][j] = arr[i][j] + min;
        }
    return *min_element(&arr[n - 1][0], &arr[n - 1][k - 1] + 1);
}
