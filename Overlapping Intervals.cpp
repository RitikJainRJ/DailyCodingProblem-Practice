#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void mergeInterval(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        mergeInterval(n);
        cout << endl;
    }
    return 0;
}

void mergeInterval(int n){
    pii arr[n];

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] ={a, b};
    }
    sort(arr, arr + n);
    int i = 0, j, max = arr[i].second;
    for(j = 1; j < n; j++){
        if(arr[j].first <= max){
            if(max < arr[j].second)
                max = arr[j].second;
            continue;
        }
        else{
            cout << arr[i].first << " " << max << " ";
            i = j;
            max = arr[i].second;
        }
    }
    if(max < arr[j - 1].second)
        max = arr[j - 1].second;
    cout << arr[i].first << " " << max << " ";
}
