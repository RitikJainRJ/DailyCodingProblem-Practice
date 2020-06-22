#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<int> stabsPoint(vector<pii>&);

int main(){
    int t, n, a, b;

    cin >> t;
    while(t--){
        cin >> n;
        vector<pii> vec(n);
        vector<int> res;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            vec[i] = {a, b};
        }
        res = stabsPoint(vec);
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
    }
    return 0;
}

vector<int> stabsPoint(vector<pii> &inter){
    vector<int> res;
    int max;

    sort(inter.begin(), inter.end(), [&](pii &a, pii &b){
        return a.second < b.second;
    });
    max = inter[0].second;
    for(int i = 1; i < inter.size(); i++){
        if(inter[i].first > max){
            res.push_back(max);
            max = inter[i].second;
        }
    }
    res.push_back(max);
    return res;
}
