#include<bits/stdc++.h>
using namespace std;

int findIndex(int);
int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << findIndex(n) << endl;
    }
	return 0;
}

int findIndex(int n){
    int arr[n], k, pivot;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    pivot = findPivot(arr, 0, n - 1);
    if(pivot == -1)
        return binarySearch(arr, 0, n - 1, k);
    if(arr[pivot] == k)
        return pivot;
    else if(arr[0] <= k)
        return binarySearch(arr, 0, pivot - 1, k);
    else
        return binarySearch(arr, pivot + 1, n - 1, k);
}

int findPivot(int arr[], int l, int r){
    if(l > r)
        return -1;
    if(l == r)
        return l;
    int m = (l + r) / 2;

    if(m < r && arr[m] > arr[m + 1])
        return m;
    if(l < m && arr[m - 1] > arr[m])
        return m - 1;
    if(arr[l] >= arr[m])
        return findPivot(arr, l, m - 1);
    else
        return findPivot(arr, m + 1, r);
}

int binarySearch(int arr[], int low, int high, int key){
    if(high < low)
        return -1;

    int mid = (low + high) / 2;
    if(key == arr[mid])
        return mid;
    if(key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid -1), key);
}
