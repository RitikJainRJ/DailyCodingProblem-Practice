/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a
space-separated sequence of dictionary words. See following examples for more details.
*/
#include<bits/stdc++.h>
using namespace std;

struct trieNode{
    unordered_map<char, trieNode*> om;
    bool isEnd;
};

int wordBreak(int);
trieNode* createNode();
void insertString(trieNode**, string);
bool searchString(trieNode*, string);
bool _wordBreak(trieNode*, string);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << wordBreak(n) << endl;
    }
    return 0;
}

trieNode* createNode(){
    trieNode *temp = nullptr;

    temp = new trieNode;
    temp->isEnd = false;
    return temp;
}

void insertString(trieNode **root, string str){
    trieNode *t = nullptr;

    if(*root == nullptr)
        *root = createNode();
    t = *root;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(t->om.find(ch) == t->om.end())
            t->om[ch] = createNode();
        t = t->om[ch];
    }
    t->isEnd = true;
}

bool searchString(trieNode *root, string str){
    trieNode *t = root;

    if(root == nullptr)
        return false;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(t->om.find(ch) == t->om.end())
            return false;
        t = t->om[ch];
    }
    if(t->isEnd == true)
        return true;
    else
        return false;
}

int wordBreak(int n){
    string dic[n], str;
    trieNode *root = nullptr;

    for(int i = 0; i < n; i++)
        cin >> dic[i];
    cin >> str;
    for(int i = 0; i < n; i++)
        insertString(&root, dic[i]);
    return _wordBreak(root, str);
}

bool _wordBreak(trieNode *root, string str){
    if(str.length() == 0)
        return true;
    for(int i = 1; i <= str.length(); i++){
        if(searchString(root, str.substr(0, i)) && _wordBreak(root, str.substr(i, str.length() - i)))
            return true;
    }
    return false;
}
