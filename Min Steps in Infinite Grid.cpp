int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int res = 0, n = A.size();

    for(int i = 1; i < n; i++){
        int temp1 = abs(A[i - 1] - A[i]);
        int temp2 = abs(B[i - 1] - B[i]);
        int temp3 = max(temp1, temp2);
        res += temp3;
    }
    return res;
}
