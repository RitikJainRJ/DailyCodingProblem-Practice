#include<bits/stdc++.h>
using namespace std;

void grayCode(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        grayCode(n);
        cout << endl;
    }
    return 0;
}

void grayCode(int n){
    stack<string> s;
    int k = n;
    string str;
    unordered_set<string> us;

    while(k--)
        str = str + '0';
    s.push(str);
    while(!s.empty()){
        string temp = s.top();
        s.pop();

        if(us.find(temp) == us.end()){
            cout << temp << " ";
            us.insert(temp);
        }
        for(int i = 0; i < n; i++){
            string t = temp;
            if(t[i] == '0')
                t[i] = '1';
            else
                t[i] = '0';
            if(us.find(t) == us.end())
                s.push(t);
        }
    }
}
