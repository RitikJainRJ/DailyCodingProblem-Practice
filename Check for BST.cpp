bool _isBST(Node*, int, int);

bool isBST(Node* root){
    return _isBST(root, INT_MIN, INT_MAX);
}

bool _isBST(Node *root, int min, int max){
    if(!root)
        return true;
    if(min <= root->data && root->data <= max)
        return _isBST(root->left, min, root->data) && _isBST(root->right, root->data, max);
    else
        return false;
}
