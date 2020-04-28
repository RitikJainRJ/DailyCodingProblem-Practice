#include<bits/stdc++.h>
using namespace std;

class Tree{
private:
    int n;
    vector<int> *arr;
    bool *visited;

public:
    Tree(int n){
        this->n = n;
        arr = new vector<int>[n];
        visited = new bool[n];

        for(int i = 0; i < n; i++)
            visited[i] = false;
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int diameter(int u, int &res){
        int max1 = 0, max2 = 0;
        visited[u] = true;
        for(int i = 0; i < arr[u].size(); i++){
            if(visited[arr[u][i]] == false){
                int temp = diameter(arr[u][i], res);
                if(temp > max1){
                    max2 = max1;
                    max1 = temp;
                }
                else if(temp > max2)
                    max2 = temp;
            }
        }
        if(res < max1 + max2 + 1)
            res = max1 + max2 + 1;
        return 1 + max(max1, max2);
    }
};

int main(){
    Tree root(10);
    int res = 0;

    root.addEdge(0, 1);
    root.addEdge(1, 2);
    root.addEdge(2, 3);
    root.addEdge(2, 4);
    root.addEdge(4, 5);
    root.addEdge(2, 9);
    root.addEdge(1, 6);
    root.addEdge(6, 7);
    root.addEdge(6, 8);
    root.diameter(0, res);
    cout << res - 1 << endl;
    return 0;
}
