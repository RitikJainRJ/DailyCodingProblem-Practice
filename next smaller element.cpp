#include<bits/stdc++.h>
using namespace std;

void nextSmallCount(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        nextSmallCount(n);
        cout << endl;
    }
    return 0;
}

void nextSmallCount(int n){
    int arr[n], count[n];
    multiset<int> os;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n - 1; i >= 0; i--){
        os.insert(arr[i]);
        count[i] = distance(os.begin(), os.find(arr[i]));
    }
    for(int i = 0; i < n; i++)
        cout << count[i] << " ";
}
