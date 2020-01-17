#include<bits/stdc++.h>
using namespace std;

string isBal(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << isBal(str) << endl;
    }
    return 0;
}

string isBal(string str){
    stack<char> s;

    if(str.length() % 2 != 0)
        return "not balanced";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
            s.push(str[i]);
        else if(str[i] == '}'){
            if(s.empty())
                return "not balanced";
            char ch = s.top();
            s.pop();
            if(ch != '{')
                return "not balanced";
        }
        else if(str[i] == ']'){
            if(s.empty())
                return "not balanced";
            char ch = s.top();
            s.pop();
            if(ch != '[')
                return "not balanced";
        }
        else if(str[i] == ')'){
            if(s.empty())
                return "not balanced";
            char ch = s.top();
            s.pop();
            if(ch != '(')
                return "not balanced";
        }
    }
    return "balanced";
}
