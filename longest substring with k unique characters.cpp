/*
Given a string you need to print the size of the longest possible substring that has exactly k
unique characters. If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.
*/
#include<bits/stdc++.h>
using namespace std;

int longestString(string, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k;
    string str;

    cin >> t;
    while(t--){
        cin >> str >> k;
        cout << longestString(str, k) << endl;
    }
    return 0;
}

int longestString(string str, int k){
    int res = 0, temp, flag = 0;
    unordered_set<char> us;

    for(int i = 0; i < str.length(); i++){
        us.clear();
        temp = 0;
        for(int j = i; j < str.length(); j++){
            if(us.size() < k){
                temp++;
                us.insert(str[j]);
            }
            else if(us.size() == k){
                flag = 1;
                if(us.find(str[j]) != us.end())
                    temp++;
                else
                    break;
            }
        }
        if(res < temp)
            res = temp;
    }
    if(flag == 0)
        return -1;
    return res;
}
