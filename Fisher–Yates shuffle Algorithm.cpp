#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int n = 52, arr[52];

    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    for(int i = n - 1; i >= 1; i--){
        int index = rand() % (i + 1);
        swap(arr[i], arr[index]);
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
