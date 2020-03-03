/*
1
3 3
0 1
0 2
1 2
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int n;
    list<int> *arr;
    int *indegree;

    void _topological(vector<int> &vec, int visited[]){
        if(vec.size() == n){
            for(int i = 0; i < n; i++)
                cout << vec[i] << " ";
            cout << endl;
            return;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0 && visited[i] == 0){
                visited[i] = 1;
                vec.push_back(i);
                for(auto it = arr[i].begin(); it != arr[i].end(); it++)
                    indegree[*it]--;
                _topological(vec, visited);
                vec.pop_back();
                for(auto it = arr[i].begin(); it != arr[i].end(); it++)
                    indegree[*it]++;
                visited[i] = 0;
            }
        }
    }

    public:
    Graph(int n){
        this->n = n;
        arr = new list<int>[n];
        indegree = new int[n];
        for(int i = 0; i < n; i++)
            indegree[i] = 0;
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        indegree[v]++;
    }

    void topologicalSort(){
        vector<int> vec;
        int visited[n];

        memset(visited, 0, sizeof(visited));
        _topological(vec, visited);
    }
};

int main(){
    int t, n, e;

    cin >> t;
    while(t--){
        cin >> n >> e;
        Graph g(n);

        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            g.addEdge(a, b);
        }
        g.topologicalSort();
    }
    return 0;
}
