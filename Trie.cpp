/*
Trie is an efficient information retrieval data structure.
Use this data structure to store Strings and search strings.
Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.
1
10
the a there answer any by bye their hero heroplane
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    map<char, node*> om;
    bool isEnd;
};

node* getNode();
void insertString(node**, string);
int searchString(node*, string);
void deleteString(node*, string);
node* _deleteString(node*, string, int);

void Trie(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    Trie(n);
	}
	return 0;
}

void Trie(int n){
    string arr[n], res;
    node *root = nullptr;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        insertString(&root, arr[i]);
    while(1){
        int a;
        string str;
        cin >> a;

        switch(a){
            case 1: cin >> str;
                    deleteString(root, str);
                    break;
            case 2: cin >> str;
                    if(searchString(root, str))
                        cout << "Yes" << endl;
                    else
                        cout << "No" << endl;
                    break;
            default: return;
        }
    }
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

int searchString(node *root, string str){
    if(root == nullptr){
        return 0;
    }
    for(int i = 0; i < str.length(); i++){
        if(root->om.find(str[i]) == root->om.end()){
            return 0;
        }
        root = root->om[str[i]];
    }
    if(root->isEnd == true)
        return 1;
    else
        return 0;
}

void deleteString(node *root, string str){
    int i = 0;

    if(!searchString(root, str)){
        cout << "No" << endl;
        return;
    }
    _deleteString(root, str, i);
}

node* _deleteString(node *root, string str, int index){
    if(index == str.length()){
        root->isEnd = false;
        if(root->om.empty()){
            return nullptr;
        }
        else{
            return root;
        }
    }
    else{
        char ch = str[index];
        node *temp;

        temp = _deleteString(root->om[ch], str, index + 1);
        if(temp){
            return root;
        }
        else{
            root->om.erase(ch);
            if(root->isEnd == true)
                return root;
            else{
                if(root->om.empty())
                    return nullptr;
                else
                    return root;
            }
        }
    }
}
