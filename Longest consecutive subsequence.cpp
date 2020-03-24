#include<bits/stdc++.h>
using namespace std;

int longConsSeq(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << longConsSeq(n) << endl;
    }
    return 0;
}

int longConsSeq(int n){
    int arr[n], ans = 0;
    unordered_set<int> us;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        us.insert(arr[i]);
    for(int i = 0; i < n; i++){
        if(us.find(arr[i] - 1) == us.end()){
            int temp = arr[i], res = 0;
            while(us.find(temp) != us.end()){
                res++;
                temp++;
            }
            ans = max(res, ans);
        }
    }
    return ans;
}
