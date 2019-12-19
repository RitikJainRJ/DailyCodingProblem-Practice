/*
https://www.geeksforgeeks.org/reservoir-sampling/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(NULL));
    int k, temp, n = 0;

    cin >> k;
    int reservoir[k];
    for(int i = 0; i < k; i++, n++)
        cin >> reservoir[i];
    while(1){
        cin >> temp;
        if(temp == -1)
            break;
        int index = (rand() % (n + 1));
        if(index < k)
            reservoir[index] = temp;
        n++;
    }
    for(int i = 0; i < k; i++)
        cout << reservoir[i] << " ";
    cout << endl;
    return 0;
}
