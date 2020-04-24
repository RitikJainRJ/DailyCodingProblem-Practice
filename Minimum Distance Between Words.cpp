#include<bits/stdc++.h>
using namespace std;

int minDist(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << minDist(n) << endl;
    }
    return 0;
}

int minDist(int n){
    string arr[n];
    string w1, w2;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> w1 >> w2;

    int i = 0, j, counter = 0;
    int c1 = 0, c2 = 0, res = INT_MAX;
    for(j = 0; j < n; j++){
        if(arr[j] == w1){
            if(c1 == 0){
                c1++;
                counter++;
            }
            else
                c1++;
        }
        if(arr[j] == w2){
            if(c2 == 0){
                counter++;
                c2++;
            }
            else
                c2++;
        }
        if(counter == 2){
            while((arr[i] != w1 && arr[i] != w2) || (arr[i] == w1 && c1 > 1) || (arr[i] == w2 && c2 > 1)){
                if(arr[i] == w1 && c1 > 1)
                    c1--;
                if(arr[i] == w2 && c2 > 1)
                    c2--;
                i++;
            }
            int d = j - i - 1;
            if(d < res)
                res = d;
        }
    }
    return res;
}
