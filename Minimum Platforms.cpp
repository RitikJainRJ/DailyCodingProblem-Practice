#include<bits/stdc++.h>
using namespace std;

int maxPlatform(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxPlatform(n) << endl;
    }
    return 0;
}

int maxPlatform(int n){
    int arr[n], dep[n], count = 0;
    pair<int, int> sol[n];
    bool visited[n];

    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> dep[i];
    for(int i = 0; i < n; i++)
        sol[i] = {arr[i], dep[i]};
    sort(sol, sol + n);
    while(1){
        int temp, i, flag = 0;
        for(i = 0; i < n; i++)
            if(visited[i] == false){
                temp = sol[i].second;
                visited[i] = true;
                flag = 1;
                break;
            }
        for(; i < n; i++){
            if(visited[i] == false){
                if(temp < sol[i].first){
                    temp = sol[i].second;
                    visited[i] = true;
                    flag = 1;
                }
            }
        }
        if(flag == 0)
            break;
        count++;
    }
    return count;
}
