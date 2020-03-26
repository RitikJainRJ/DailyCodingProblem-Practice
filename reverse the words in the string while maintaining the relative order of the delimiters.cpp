#include<bits/stdc++.h>
using namespace std;

string reverseWord(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << reverseWord(str) << endl;
    }
    return 0;
}

string reverseWord(string str){
    stack<string> s;
    queue<string> q;
    bool flag = true;
    string res;

    if('a' <= str[0] && str[0] <= 'z')
        flag = false;
    int i = 0, j;
    for(j = 0; j < str.length(); j++){
        if(flag == false){
            if(!('a' <= str[j] && str[j] <= 'z')){
                string temp = str.substr(i, j - i);
                s.push(temp);
                flag = true;
                i = j;
            }
        }
        else{
            if('a' <= str[j] && str[j] <= 'z'){
                string temp = str.substr(i, j - i);
                q.push(temp);
                flag = false;
                i = j;
            }
        }
    }
    if(flag == false){
        string temp = str.substr(i, j - i);
        s.push(temp);
    }
    else{
        string temp = str.substr(i, j - i);
        q.push(temp);
    }
    flag = true;
    if('a' <= str[0] && str[0] <= 'z')
        flag = false;
    if(flag == false){
        res += s.top();
        s.pop();
    }
    while(!q.empty() || !s.empty()){
        if(!q.empty()){
            res += q.front();
            q.pop();
        }
        if(!s.empty()){
            res += s.top();
            s.pop();
        }
    }
    return res;
}
