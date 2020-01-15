#include<bits/stdc++.h>
using namespace std;

int maxPlatform(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxPlatform(n) << endl;
    }
    return 0;
}

int maxPlatform(int n){
    multimap<int, int> om;
    multimap<int, int>::iterator it, it2;
    int arr[n], dep[n], count = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> dep[i];
    for(int i = 0; i < n; i++)
        om.insert({arr[i], dep[i]});
    while(!om.empty()){
        count++;
        it = om.begin();
        int temp = it->first;
        while(it != om.end()){
            if(temp <= it->first){
                temp = it->second;
                it2 = it;
                it2++;
                om.erase(it);
                it = it2;
            }
            else
                it++;
        }
    }
    return count;
}
