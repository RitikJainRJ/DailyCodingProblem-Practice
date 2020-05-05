int Solution::solve(vector<int> &A, int B, int C, int D) {
    int count[1001], res = 0;

    memset(count, 0, sizeof(count));
    for(int i = 0; i < A.size(); i++)
        count[A[i]]++;
    for(int i = 1; i < 1001; i++){
        if(count[i] == 0)
            continue;
        for(int j = 0; j < i; j++){
            if(count[j] == 0)
                continue;
            if((i + j) % B == C && (i * j) % B == D)
                res = res + (count[i] * count[j]);
        }
        if((i + i) % B == C && (i * i) % B == D)
            res = res + (count[i] * (count[i] - 1) / 2);
    }
    return res;
}
