#include<bits/stdc++.h>
using namespace std;

void nearLargeNum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        nearLargeNum(n);
        cout << endl;
    }
    return 0;
}

void nearLargeNum(int n){
    int arr[n], res[n];
    stack<int> s;

    memset(res, -1, sizeof(res));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] > arr[i]){
            if(!s.empty())
                res[i] = s.top();
            s.push(i);
            i++;
        }
        else{
            int temp = s.top();
            s.pop();
            if(res[temp] != -1){
                int x = abs(temp - res[temp]);
                if(x > (i - temp)){
                    res[temp] = i;
                }
            }
            else
                res[temp] = i;
        }
    }
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}
