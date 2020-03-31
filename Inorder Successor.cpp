void _inOrderSucc(Node*, Node*, Node*&);

Node* inOrderSuccessor(Node *root, Node *x){
    Node *res = nullptr;
    _inOrderSucc(root, x, res);
    return res;
}

void _inOrderSucc(Node *root, Node *x, Node *&res){
    if(root == nullptr){
        return;
    }
    else{
        if(x->data < root->data){
            res = root;
            _inOrderSucc(root->left, x, res);
        }
        else{
            _inOrderSucc(root->right, x, res);
        }
    }
}
