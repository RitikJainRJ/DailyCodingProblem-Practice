/*
1
4
chennai banglore
bombay delhi
goa chennai
delhi goa
*/
#include<bits/stdc++.h>
using namespace std;

void findItinerary(int);
void _findItinerary(map<string, string>&, vector<pair<string, string>>);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        findItinerary(n);
        cout << endl;
    }
    return 0;
}

void findItinerary(int n){
    map<string, string> om;
    map<string, string>::iterator it;

    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        om[a] = b;
    }
    for(it = om.begin(); it != om.end(); it++){
        vector<pair<string, string>> vec;
        vec.push_back({it->first, it->second});
        _findItinerary(om, vec);
    }
}

void _findItinerary(map<string, string> &om, vector<pair<string, string>> vec){
    if(vec.size() == om.size()){
        cout << "[";
        for(int i = 0; i < vec.size(); i++){
            cout << "('" << vec[i].first << "','" << vec[i].second << "')";
        }
        cout << "]";
        return;
    }
    pair<string, string> temp = vec.back();
    map<string, string>::iterator it;
    it = om.find(temp.second);
    if(it != om.end()){
        vec.push_back({it->first, it->second});
        _findItinerary(om, vec);
    }
}
