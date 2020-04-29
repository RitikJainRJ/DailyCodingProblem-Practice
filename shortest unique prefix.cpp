#include<bits/stdc++.h>
using namespace std;

struct Trie{
    unordered_map<char, Trie*> um;
    bool isEnd;
    int f;
};

void shortUniPre(int);
Trie* createNode();
void insertString(Trie**, string);
void findPrefix(Trie*, string);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        shortUniPre(n);
        cout << endl;
    }
    return 0;
}

Trie* createNode(){
    Trie *root = new Trie;
    root->isEnd = false;
    root->f = 0;
    return root;
}

void insertString(Trie **root, string str){
    Trie *t = nullptr;

    if(*root == nullptr)
        *root = createNode();
    t = *root;
    for(int i = 0; i < str.length(); i++){
        if(t->um.find(str[i]) == t->um.end())
            t->um[str[i]] = createNode();
        t->um[str[i]]->f++;
        t = t->um[str[i]];
    }
    t->isEnd = true;
}

void shortUniPre(int n){
    string arr[n];
    Trie *root = nullptr;
    string res;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        insertString(&root, arr[i]);
    findPrefix(root, res);
}

void findPrefix(Trie *root, string res){
    if(root->f == 1){
        cout << res << " ";
        return;
    }
    if(root->isEnd == true)
        cout << res << " ";
    for(auto it = root->um.begin(); it != root->um.end(); it++)
        findPrefix(it->second, res + it->first);
}
