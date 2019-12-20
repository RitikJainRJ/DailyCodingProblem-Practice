/*
Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
*/
#include<bits/stdc++.h>
using namespace std;

bool findItinerary(unordered_map<string, string>&, unordered_map<string, string>::iterator, vector<pair<string, string>>, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string, string> um;
    int n;
    string s1, s2;
    vector<pair<string, string>> vec;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        um[s1] = s2;
    }
    for(auto it = um.begin(); it != um.end(); it++){
        if(findItinerary(um, it, vec, n))
            return 0;
    }
    cout << "Not Exist" << endl;
    return 0;
}

bool findItinerary(unordered_map<string, string> &um, unordered_map<string, string>::iterator it, vector<pair<string, string>> vec, int n){
    vec.push_back({it->first, it->second});
    if(vec.size() == n){
        for(auto itr = vec.begin(); itr != vec.end(); itr++)
            cout << itr->first << "-->" << itr->second << ", ";
        cout << endl;
        return true;
    }
    auto temp = um.find(it->second);
    if(temp != um.end()){
        return findItinerary(um, temp, vec, n);
    }
    return false;
}
