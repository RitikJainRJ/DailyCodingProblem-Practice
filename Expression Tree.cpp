int evalTree(node* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return stoi(root->data);
    else{
        int a = evalTree(root->left);
        int b = evalTree(root->right);

        if(root->data == "+")
            return a + b;
        if(root->data == "-")
            return a - b;
        if(root->data == "*")
            return a * b;
        if(root->data == "/")
            return a / b;
    }
}
