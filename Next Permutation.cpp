#include<bits/stdc++.h>
using namespace std;

void nextPermutation(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        nextPermutation(n);
        cout << endl;
    }
    return 0;
}

void nextPermutation(int n){
    int arr[n];
    bool flag = false;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        if(arr[i - 1] < arr[i])
            flag = true;
    if(flag == false){
        for(int i = n - 1; i >= 0; i--)
            cout << arr[i] << " ";
        return;
    }
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < arr[i + 1]){
            int a = i, min = INT_MAX, b;

            for(int j = i + 1; j < n; j++){
                if(min > arr[j] && arr[j] >= arr[i]){
                    min = arr[j];
                    b = j;
                }
            }
            swap(arr[a], arr[b]);
            sort(arr + a + 1, arr + n);
            break;
        }
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
