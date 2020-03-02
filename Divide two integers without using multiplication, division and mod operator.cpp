#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;

    cin >> t;
    while(t--){
        int count = 0;
        bool flag = false;
        cin >> a >> b;
        if(a < 0 && b < 0){
            a = abs(a);
            b = abs(b);
        }
        else if(a < 0){
            flag = true;
            a = abs(a);
        }
        else if(b < 0){
            flag = true;
            b = abs(b);
        }
        while(a){
            a = a - b;
            if(a < 0)
                break;
            count++;
        }
        if(flag)
            cout << "-";
        cout << count << endl;
    }
}
