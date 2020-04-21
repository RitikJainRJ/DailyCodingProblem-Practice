vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> res;

    for(int i = n - 1; i > 0; i--){
        int index, max = INT_MIN;
        for(int j = 0; j <= i; j++){
            if(max < A[j]){
                max = A[j];
                index = j;
            }
        }
        res.push_back(index + 1);
        reverse(&A[0], &A[index + 1]);
        res.push_back(i + 1);
        reverse(&A[0], &A[i + 1]);
    }
    return res;
}
