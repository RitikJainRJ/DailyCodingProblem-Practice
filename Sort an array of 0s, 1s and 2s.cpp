#include<bits/stdc++.h>
using namespace std;

void sort012(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        sort012(n);
        cout << endl;
    }
    return 0;
}

void sort012(int n){
    int arr[n];
    int lo = 0, mid = 0, hi = n - 1;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    while(mid <= hi){
        if(arr[mid] == 0)
            swap(arr[lo++], arr[mid++]);
        else if(arr[mid] == 1)
            mid++;
        else if(arr[mid] == 2)
            swap(arr[mid], arr[hi--]);
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
