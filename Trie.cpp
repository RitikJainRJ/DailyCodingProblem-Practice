/*
Trie is an efficient information retrieval data structure.
Use this data structure to store Strings and search strings.
Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    map<char, node*> om;
    bool isEnd;
};

node* getNode();
void insertString(node**, string);
void searchString(node*, string);

void Trie(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    Trie(n);
	    cout << endl;
	}
	return 0;
}

void Trie(int n){
    string arr[n], res;
    node *root = nullptr;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> res;
    for(int i = 0; i < n; i++)
        insertString(&root, arr[i]);
    searchString(root, res);
}

node* getNode(){
    node *t = nullptr;

    t = new node;   // this is thing
    t->isEnd = false;
    return t;
}

void insertString(node **root, string str){
    node *temp = nullptr;

    if(*root == nullptr)
        *root = getNode();
    temp = *root;
    for(int i = 0; i < str.length(); i++){
        if(temp->om.find(str[i]) == temp->om.end()){
            temp->om[str[i]] = getNode();
        }
        temp = temp->om[str[i]];
    }
    temp->isEnd = true;
}

void searchString(node *root, string str){
    if(root == nullptr){
        cout << 0;
        return;
    }
    for(int i = 0; i < str.length(); i++){
        if(root->om.find(str[i]) == root->om.end()){
            cout << 0;
            return;
        }
        root = root->om[str[i]];
    }
    if(root->isEnd == true)
        cout << 1;
    else
        cout << 0;
}
