#include<bits/stdc++.h>
using namespace std;

int calculate(int, int);

int main(){
    int n1 = 0, n2 = 0, t, T;
    srand(time(NULL));

    cin >> t;
    T = t;
    while(t--){
        n1 += calculate(5, 6);
        n2 += calculate(5, 5);
    }
    cout << n1 / T << " " << n2 / T << endl;
    return 0;
}

int calculate(int x, int y){
    int count, a, b, c;

    count = 2;
    a = (rand() % 6) + 1;
    b = (rand() % 6) + 1;
    while(1){
        if(a == x && b == y)
            return count;
        count++;
        c = (rand() % 6) + 1;
        a = b;
        b = c;
    }
    return count;
}
