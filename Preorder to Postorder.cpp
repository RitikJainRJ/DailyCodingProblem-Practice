#include<bits/stdc++.h>
using namespace std;

void printPostorder(int[], int[], int&, int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int pre[n], in[n], index = 0;

        for(int i = 0; i < n; i++){
            cin >> pre[i];
            in[i] = pre[i];
        }
        sort(in, in + n);
        printPostorder(pre, in, index, 0, n - 1);
        cout << endl;
    }
    return 0;
}

void printPostorder(int pre[], int in[], int &index, int l, int r){
    if(l > r)
        return;
    int i, temp = pre[index];
    for(i = l; i <= r; i++)
        if(in[i] == temp)
            break;
    index++;
    if(l != r){
        printPostorder(pre, in, index, l, i - 1);
        printPostorder(pre, in, index, i + 1, r);
    }
    cout << temp << " ";
}
