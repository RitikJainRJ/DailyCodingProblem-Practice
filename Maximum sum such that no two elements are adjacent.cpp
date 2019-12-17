/*
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that
no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10)
or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
Answer the question in most efficient way.
*/
#include<bits/stdc++.h>
using namespace std;

void findMax(int);
//void _findMax(int[], int, int, int&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        findMax(n);
        cout << endl;
    }
    return 0;
}

// recursive way
/*void findMax(int n){
    int arr[n], weight = 0, max_weight = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    _findMax(arr, n - 1, weight, max_weight);
    cout << max_weight;
}

void _findMax(int arr[], int index, int w, int &mw){
    if(index == 0){
        int temp = w + arr[index];
        if(mw < temp)
            mw = temp;
    }
    else if(index == 1){
        _findMax(arr, index - 1, w, mw);
        int temp = w + arr[index];
        if(mw < temp)
            mw = temp;
    }
    else{
        _findMax(arr, index - 1, w, mw);

        for(int i = index - 2; i >= 0; i--)
            _findMax(arr, i, w + arr[index], mw);
    }
}*/

void findMax(int n){
    int arr[n], store[n];

    memset(store, 0, sizeof(store));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    store[0] = arr[0];
    store[1] = arr[1];
    for(int i = 2; i < n; i++)
        store[i] = max(arr[i] + store[i - 2], store[i - 1]);
    cout << store[n - 1];
}
