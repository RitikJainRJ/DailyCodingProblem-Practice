/*
Given a binary tree, write a program to count the number of Single Valued Subtrees.
A Single Valued Subtree is one in which all the nodes have same value.
Expected time complexity is O(n).
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* newNode(int);
int countUnivalTree(node*);
bool isUT(node*, int&);

int main(void){
    node* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);

    cout << countUnivalTree(root) << endl;
    return 0;
}

node* newNode(int data){
    node *temp = nullptr;

    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

int countUnivalTree(node *root){
    int c = 0;
    isUT(root, c);
    return c;
}

bool isUT(node *root, int &c){
    if(!root)
        return true;
    if(!root->left && !root->right){
        c++;
        return true;
    }
    else{
        bool temp = false;
        if(isUT(root->left, c) && isUT(root->right, c)){
            if(root->left && root->right){
                if(root->data == root->left->data && root->data == root->right->data)
                    temp = true;
            }
            else if(root->left && root->data == root->left->data)
                    temp = true;
            else if(root->right && root->data == root->right->data)
                    temp = true;
        }
        if(temp == true)
            c++;
        return temp;
    }
}
