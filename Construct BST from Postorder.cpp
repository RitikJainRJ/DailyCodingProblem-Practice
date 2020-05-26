Node* construct(int&, int[], int, int);

Node *constructTree (int post[], int n){
    int ind = n - 1;
    return construct(ind, post, INT_MIN, INT_MAX);
}

Node* construct(int &ind, int post[], int min, int max){
    int x = post[ind];
    if(!(min <= x && x <= max) || ind < 0)
        return nullptr;
    ind--;
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = x;
    root->right = construct(ind, post, x, max);
    root->left = construct(ind, post, min, x);
    return root;
}
