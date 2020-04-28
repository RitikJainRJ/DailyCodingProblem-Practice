#include<bits/stdc++.h>
using namespace std;

string anagramPalin(string);

int main(){
	int t;
	string str;

	cin >> t;
	while(t--){
	    cin >> str;
	    cout << anagramPalin(str) << endl;
	}
	return 0;
}

string anagramPalin(string str){
    unordered_map<char, int> um;
    bool flag = false;

    for(int i = 0; i < str.length(); i++)
        um[str[i]]++;
    for(auto it = um.begin(); it != um.end(); it++){
        if(it->second % 2 != 0){
            if(!flag)
                flag = true;
            else
                return "No";
        }
    }
    return "Yes";
}
