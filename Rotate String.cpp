class Solution {
public:
    bool rotateString(string A, string B) {
        int n = A.length(), m = B.length();

        if(n != m)
            return false;
        if(n == 0)
            return true;

        for(int i = 0; i < n; i++){
            if(A[i] == B[0]){
                int j, k;
                for(j = 0, k = i; j < m; j++, k = (k + 1) % n){
                    if(A[k] != B[j])
                        break;
                }
                if(j == m)
                    return true;
            }
        }
        return false;
    }
};
