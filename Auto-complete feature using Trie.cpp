/*
All operation of TRIE with hash Map.

8
the a there answer any by bye their
4
abc abcd aa abbbaba
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    map<char, node*> om;
    bool isEnd;
};

node* getNode();
void insertString(node*&, string);
string searchString(node*, string);
node* deleteString(node*, string, int);
void autoComplete(node*, string);
void displayAll(node*);
void _displayAll(node*, string);

int main(){
    node *root = nullptr;
    int n, a;
    string str;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        insertString(root, str);
    }
    while(1){
        cin >> a;
        switch(a){
            case 1: cin >> str;
                    cout << searchString(root, str) << endl;
                    break;
            case 2: cin >> str;
                    if(searchString(root, str) == "No")
                        cout << "Not Exist" << endl;
                    else
                        root = deleteString(root, str, 0);
                    break;
            case 3: cin >> str;
                    autoComplete(root, str);
                    break;
            case 4: displayAll(root);
                    break;
            default: return 0;
        }
    }
    return 0;
}

node* getNode(){
    node *temp = nullptr;

    temp = new node;
    temp->isEnd = false;
    return temp;
}

void insertString(node *&root, string str){
    node *temp = nullptr;

    if(root == nullptr)
        root = getNode();
    temp = root;
    for(int i = 0; i < str.length(); i++){
        if(temp->om.find(str[i]) == temp->om.end())
            temp->om[str[i]] = getNode();
        temp = temp->om[str[i]];
    }
    temp->isEnd = true;
}

string searchString(node *root, string str){
    node *temp = nullptr;

    if(root == nullptr)
        return "No";
    temp = root;
    for(int i = 0; i < str.length(); i++){
        if(temp->om.find(str[i]) == temp->om.end())
            return "No";
        temp = temp->om[str[i]];
    }
    if(temp->isEnd == true)
        return "Yes";
    else
        return "No";
}

node* deleteString(node *root, string str, int index){
    if(index == str.length()){
        root->isEnd = false;
        if(root->om.empty())
            return nullptr;
        else
            return root;
    }
    else{
        char ch = str[index];
        node *temp = nullptr;

        temp = deleteString(root->om[ch], str, index + 1);
        if(temp == nullptr){
            root->om.erase(ch);
            if(root->isEnd == true)
                return root;
            if(root->om.empty())
                return nullptr;
            else
                return root;
        }
        else{
            return root;
        }
    }
}

void displayAll(node *root){
    string res;

    if(root == nullptr){
        cout << "Nothing exist" << endl;
        return;
    }
    _displayAll(root, res);
}

void autoComplete(node *root, string str){
    for(int i = 0; i < str.length(); i++){
        root = root->om[str[i]];
    }
    _displayAll(root, str);
}

void _displayAll(node *root, string res){
    map<char, node*>::iterator it;
    if(root->isEnd == true)
        cout << res << " ";
    if(root->om.empty())
        return;
    for(it = root->om.begin(); it != root->om.end(); it++){
        _displayAll(it->second, res + it->first);
    }
}
