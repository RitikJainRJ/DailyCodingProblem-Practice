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
    vector<int> smallestRange(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<Node, vector<Node>, myComp> pq;
        vector<int> res;
        int max_ele = 0, min_ele;
        int dis, s, e;
        int k = arr.size();

        for(int i = 0; i < k; i++){
            pq.push(Node(arr[i][0], i, 0));
            max_ele = max(max_ele, arr[i][0]);
        }
        min_ele = pq.top().data;
        dis = max_ele - min_ele;
        s = min_ele;
        e = max_ele;
        while(1){
            Node temp = pq.top();
            pq.pop();
            int x = temp.row, y = temp.col, n = arr[x].size();
            if(y + 1 < n)
                pq.push(Node(arr[x][y + 1], x, y + 1));
            if(y + 1 < n && max_ele < arr[x][y + 1])
                max_ele = arr[x][y + 1];
            if(y + 1 == n)
                break;
            min_ele = pq.top().data;
            if(dis > max_ele - min_ele){
                dis = max_ele - min_ele;
                s = min_ele;
                e = max_ele;
            }
        }

        res.push_back(s);
        res.push_back(e);
        return res;
    }
};
