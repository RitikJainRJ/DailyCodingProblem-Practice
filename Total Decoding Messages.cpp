/*
Let 1 represent ‘A’, 2 represents ‘B’, etc.
Given a digit sequence, count the number of possible decodings of the given digit sequence.
*/
#include<bits/stdc++.h>
using namespace std;

int findWays(string, int);

int main(void){
    string str;

    cin >> str;
    cout << findWays(str, str.length()) << endl;
    return 0;
}

int findWays(string str, int n){
    if(n == 0 || n == 1)
        return 1;
    if(str[0] == '0')
        return 0;

    int count = 0;
    if(str[n - 1] > '0')
        count = findWays(str, n - 1);
    if(str[n - 2] == '1' || (str[n - 2] == '2' && str[n - 1] < '7'))
        count += findWays(str, n - 2);
    return count;
}
