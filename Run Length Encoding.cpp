#include<bits/stdc++.h>
using namespace std;

string encode(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << encode(str) << endl;
    }
    return 0;
}

string encode(string str){
    string res;

    for(int i = 0; i < str.length(); i++){
        int temp = 1;
        for(int j = i; j < str.length(); j++){
            if(str[j] == str[j + 1] && j + 1 < str.length())
                temp++;
            else{
                res.push_back(str[i]);
                res.push_back(temp + '0');
                i = j;
                break;
            }
        }
    }
    return res;
}
