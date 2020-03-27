struct Node{
    int data;
    int row;
    int col;
    Node(int d, int r, int c) : data{d}, row{r}, col{c} {}
};

class myComp{
public:
    int operator()(const Node& a, const Node& b){
        return a.data > b.data;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<Node, vector<Node>, myComp> pq;
        int n = matrix.size();

        for(int i = 0; i < n; i++)
            pq.push(Node(matrix[i][0], i, 0));

        Node temp = pq.top();
        while(k--){
            temp = pq.top();
            pq.pop();
            int x = temp.row, y = temp.col;
            if(y + 1 < n)
                pq.push(Node(matrix[x][y + 1], x, y + 1));
        }
        return temp.data;
    }
};
