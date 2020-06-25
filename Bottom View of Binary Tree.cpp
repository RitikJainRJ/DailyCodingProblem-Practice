#define pni pair<Node*, int>

void getMinMax(Node *root, int hd, int &imin, int &imax){
    if(!root)   return;
    else{
        imin = min(imin, hd);
        imax = max(imax, hd);
        getMinMax(root->left, hd - 1, imin, imax);
        getMinMax(root->right, hd + 1, imin, imax);
    }
}

vector<int> bottomView(Node *root){
    unordered_map<int, int> um;
    vector<int> res;
    queue<pni> q;
    int min = INT_MAX, max = INT_MIN;

    if(!root)   return res;
    getMinMax(root, 0, min, max);
    q.push({root, 0});
    while(!q.empty()){
        pni f = q.front();
        q.pop();

        um[f.second] = f.first->data;
        if(f.first->left)
            q.push({f.first->left, f.second - 1});
        if(f.first->right)
            q.push({f.first->right, f.second + 1});
    }
    for(int i = min; i <= max; i++)
        res.push_back(um[i]);
    return res;
}
