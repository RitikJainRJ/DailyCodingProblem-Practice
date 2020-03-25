#include<bits/stdc++.h>
using namespace std;

void reverseWords(string&);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    reverseWords(str);
	    cout << endl;
	}
	return 0;
}

void reverseWords(string &str){
    int i = 0, j;

    for(j = 0; j < str.length(); j++){
        if(str[j] == '.'){
            reverse(&str[i], &str[j]);
            i = j + 1;
        }
    }
    reverse(&str[i], &str[j]);
    reverse(&str[0], &str[j]);
    cout << str;
}
