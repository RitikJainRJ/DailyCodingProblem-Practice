int maxAreaHist(int[], int);

int maxArea(int M[MAX][MAX], int n, int m){
    int res = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++)
            if(M[i][j] != 0)
                M[i][j] += M[i - 1][j];
        int ans = maxAreaHist(M[i], m);
        if(res < ans)
            res = ans;
    }
    return res;
}

int maxAreaHist(int arr[], int n){
    stack<int> s;
    int res = 0;

    int i = 0;
    while(i < n){
        if(s.empty() || arr[s.top()] <= arr[i])
            s.push(i++);
        else{
            int temp = s.top();
            s.pop();

            int ans = arr[temp] * (s.empty() ? i : i - s.top() - 1);
            if(ans > res)
                res = ans;
        }
    }
    while(!s.empty()){
        int temp = s.top();
        s.pop();

        int ans = arr[temp] * (s.empty() ? i : i - s.top() - 1);
        if(ans > res)
            res = ans;
    }
    return res;
}
