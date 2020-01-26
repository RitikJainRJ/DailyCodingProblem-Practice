#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key){
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void secondLargest(Node *root, int &count){
    if(!root)
        return;
    secondLargest(root->right, count);
    count++;
    if(count == 2){
        cout << root->key << endl;
        return;
    }
    secondLargest(root->left, count);
}

int main(){
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int count = 0;
    secondLargest(root, count);
    return 0;
}
