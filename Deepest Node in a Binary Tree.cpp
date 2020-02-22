Node* findDeepest(Node *root){
    int max = -1;
    Node *res = nullptr;
    _findDeepest(root, 0, max, res);
    return res;
}

void _findDeepest(Node *root, int level, int &max, Node &res){
    if(root == nullptr)
        return;
    if(max < level){
        max = level;
        res = root;
    }
    _findDeepest(root->left, level + 1, max, res);
    _findDeepest(root->right, level + 1, max, res);
}
