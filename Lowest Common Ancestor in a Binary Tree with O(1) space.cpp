int _lca(Node*, int, int, Node**);

Node* lca(Node* root, int n1, int n2){
    Node *res = nullptr;
    _lca(root, n1, n2, &res);
    return res;
}

int _lca(Node* root, int n1, int n2, Node **res){
    if(!root)
        return 0;
    else{
        int left = _lca(root->left, n1, n2, res);
        int right = _lca(root->right, n1, n2, res);
        int temp = 0;

        if(root->data == n1 || root->data == n2)
            temp = 1;
        if(left == 1 && right == 1)
            *res = root;
        else if(left == 1 && temp == 1)
            *res = root;
        else if(right == 1 && temp == 1)
            *res = root;
        return left + right + temp;
    }
}

