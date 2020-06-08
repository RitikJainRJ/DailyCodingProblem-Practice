#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int n;
    vector<int> *arr;

    bool isCycle(int u, vector<bool> &visited, int parent){
        visited[u] = true;

        for(int i = 0; i < arr[u].size(); i++)
            if(!visited[arr[u][i]]){
                if(isCycle(arr[u][i], visited, u))
                    return true;
            }
            else if(arr[u][i] != parent)
                return true;
        return false;
    }

public:
    Graph(int n){
        this->n = n;
        arr = new vector<int>[n];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bool isTree(){
        vector<bool> visited(n, false);

        if(isCycle(0, visited, -1))
            return false;
        for(int i = 0; i < n; i++)
            if(visited[i] == false)
                return false;
        return true;
    }
};


int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n": cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n": cout << "Graph is not Tree\n";
    return 0;
}
