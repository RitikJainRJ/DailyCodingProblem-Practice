void inOrder(Node*, vector<int>&);

bool isPairPresent(struct Node *root, int target){
    vector<int> vec;

    inOrder(root, vec);
    int i = 0, j = vec.size() - 1;
    while(i < j){
        if(vec[i] + vec[j] > target)
            j--;
        else if(vec[i] + vec[j] < target)
            i++;
        else
            return true;
    }
    return false;
}

void inOrder(Node *root, vector<int> &vec){
    if(root){
        inOrder(root->left, vec);
        vec.push_back(root->data);
        inOrder(root->right, vec);
    }
}
