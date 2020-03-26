class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = 0, i, j;
        vector<int> res;

        for(int i = 0; i < A.size(); i++)
            if(A[i] >= 0){
                m = i;
                break;
            }
        if(m != 0)
            reverse(&A[0], &A[m]);
        for(int i = 0; i < A.size(); i++)
            A[i] = A[i] * A[i];
        i = 0;
        j = m;
        while(i < m && j < A.size()){
            if(A[i] <= A[j]){
                res.push_back(A[i]);
                i++;
            }
            else{
                res.push_back(A[j]);
                j++;
            }
        }
        while(i < m){
            res.push_back(A[i]);
            i++;
        }
        while(j < A.size()){
            res.push_back(A[j]);
            j++;
        }
        return res;
    }
};
