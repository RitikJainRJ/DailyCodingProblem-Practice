struct Info{
    int min;
    int max;
    int size;
    bool isBST;
    int answer;
};

Info _largestBST(Node*);

int largestBst(Node *root){
    return _largestBST(root).answer;
}

Info _largestBST(Node *root){
    if(root == nullptr)
        return {INT_MAX, INT_MIN, 0, true, 0};
    else if(root->left == nullptr && root->right == nullptr)
        return {root->data, root->data, 1, true, 1};
    else{
        Info linfo = _largestBST(root->left);
        Info rinfo = _largestBST(root->right);
        Info temp;
        temp.size = linfo.size + rinfo.size + 1;

        if(linfo.isBST && rinfo.isBST && linfo.max <= root->data && root->data <= rinfo.min){
            temp.answer = temp.size;
            temp.min = min({root->data, linfo.min, rinfo.min});
            temp.max = max({root->data, linfo.max, rinfo.max});
            temp.isBST = true;
            return temp;
        }
        temp.answer = max(linfo.answer, rinfo.answer);
        temp.isBST = false;
        return temp;
    }
}

