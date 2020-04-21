TreeNode* pruneTree(TreeNode* root) {
    if(!root)
        return nullptr;
    if(!root->left && !root->right){
        if(root->val == 0)
            return nullptr;
        else
            return root;
    }
    else{
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0)
            return nullptr;
        else
            return root;
    }
}
