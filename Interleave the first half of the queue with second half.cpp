#include<bits/stdc++.h>
using namespace std;

void convert(stack<int>&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        stack<int> s;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            s.push(a);
        }
        convert(s);
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    return 0;
}

void convert(stack<int> &s){
    int n = s.size();
    queue<int> q;
    int i = 1;

    while(i != n){
        while(s.size() != i){
            q.push(s.top());
            s.pop();
        }
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        i++;
    }
}
