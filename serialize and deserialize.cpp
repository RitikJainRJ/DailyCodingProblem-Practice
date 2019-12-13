#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int);
void inorder(Node*);
void serialize(Node*, vector<int>&);
Node* deSerialize(vector<int>, int&);

int main(){
    vector<int> vec;
    Node *root = nullptr;

    root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    serialize(root, vec);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    Node *root1 = nullptr;
    int index = 0;
    root1 = deSerialize(vec, index);
    printf("Inorder Traversal of the tree constructed from file:\n");
    inorder(root1);
    return 0;
}

Node* newNode(int data){
    Node *temp = nullptr;

    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void serialize(Node *root, vector<int> &vec){
    if(!root)
        vec.push_back(-1);
    else{
        vec.push_back(root->data);
        serialize(root->left, vec);
        serialize(root->right, vec);
    }
}

Node* deSerialize(vector<int> vec, int &index){
    if(vec[index] == -1 || index >= vec.size()){
        index++;
        return nullptr;
    }
    else{
        Node *temp = nullptr;

        temp = newNode(vec[index]);
        index++;
        temp->left = deSerialize(vec, index);
        temp->right = deSerialize(vec, index);
        return temp;
    }
}

