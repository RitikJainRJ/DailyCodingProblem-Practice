/*
0 0 0.9
0 1 0.075
0 2 0.025
1 0 0.15
1 1 0.8
1 2 0.05
2 0 0.25
2 1 0.25
2 2 0.5
*/
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class Graph{
private:
    int n;
    vector<pii> *arr;

    void _markov(int u, int &steps, unordered_map<int, int> &um){
        if(steps == 0)
            return;
        um[u]++;
        steps--;
        int val = (rand() % 1000) + 1;
        for(int i = 0; i < arr[u].size(); i++)
            if(arr[u][i].second >= val){
                _markov(arr[u][i].first, steps, um);
                break;
            }
    }

public:
    Graph(int n){
        this->n = n;
        arr = new vector<pii>[n];
        srand(time(NULL));
    }

    void addEdge(int u, int v, double p){
        pii temp;
        if(arr[u].empty())
            temp = {v, 1000 * p};
        else
            temp = {v, arr[u].back().second + 1000 * p};
        arr[u].push_back(temp);
    }

    void printGraph(){
        for(int i = 0; i < n; i++){
            cout << i << ":- ";
            for(int j = 0; j < arr[i].size(); j++)
                cout << arr[i][j].first << " " << arr[i][j].second << ", ";
            cout << endl;
        }
    }

    void markovChain(int steps){
        unordered_map<int, int> um;

        _markov(0, steps, um);
        for(auto it = um.begin(); it != um.end(); it++)
            cout << it->first << " " << it->second << endl;
    }
};

int main(){
    Graph g(3);

    for(int i = 0; i < 9; i++){
        int u, v;
        double p;
        cin >> u >> v >> p;
        g.addEdge(u, v, p);
    }
    g.markovChain(5000);
    return 0;
}
