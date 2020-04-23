#include<bits/stdc++.h>
using namespace std;

void randNum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        randNum(n);
        cout << endl;
    }
    return 0;
}

void randNum(int n){
    srand(time(NULL));
    int arr[n], prob[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        temp = temp * 100;
        prob[i] = temp;
    }
    for(int i = 1; i < n; i++)
        prob[i] += prob[i - 1];

    int c = 100;
    while(c--){
        int r = (rand() % 100) + 1;
        for(int i = 0; i < n; i++)
            if(r <= prob[i]){
                cout << arr[i] << " ";
                break;
            }
    }
}
