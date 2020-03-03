int _maxPathSum(Node*, int&);

int maxPathSum(Node *root){
    int res = 0;

    _maxPathSum(root, res);
    return res;
}

int _maxPathSum(Node *root, int &res){
    if(root == nullptr)
        return 0;
    else if(root->left == nullptr && root->right == nullptr)
        return root->data;
    else{
        int left = _maxPathSum(root->left, res);
        int right = _maxPathSum(root->right, res);

        if(root->left && root->right){
            int temp = left + right + root->data;
            res = max(res, temp);
            if(left < right)
                return right + root->data;
            else
                return left + root->data;
        }
        return !root->left ? right + root->data : left + root->data;
    }
}
