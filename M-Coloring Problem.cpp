#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int n;
    vector<int> *arr;
    bool _colorIt(int u, int m, int color[]);
    bool isSafe(int c, int u, int color[]);

    public:
    Graph(int n){
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int mColoringPossible(int m);
};

int Graph::mColoringPossible(int m){
    int color[n];

    memset(color, -1, sizeof(color));
    if(_colorIt(0, m, color))
        return 1;
    else
        return 0;
}

bool Graph::isSafe(int c, int u, int color[]){
    for(int i = 0; i < arr[u].size(); i++)
        if(color[arr[u][i]] == c)
            return false;
    return true;
}

bool Graph::_colorIt(int u, int m, int color[]){
    if(u == n){
        return true;
    }
    for(int i = 0; i < m; i++){
        if(isSafe(i, u, color)){
            color[u] = i;
            if(_colorIt(u + 1, m, color))
                return true;
            color[u] = -1;
        }
    }
    return false;
}

int main(){
    int t, n, m, e;

    cin >> t;
    while(t--){
        cin >> n >> m >> e;
        Graph g(n);
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g.addEdge(a, b);
        }
        cout << g.mColoringPossible(m) << endl;
    }
	return 0;
}
