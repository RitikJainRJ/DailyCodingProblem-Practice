#include<bits/stdc++.h>
using namespace std;

void printLIS(int);
void printLIS_2(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        printLIS_2(n);
        cout << endl;
    }
    return 0;
}

void printLIS_2(int n){
    int arr[n];
    vector<int> load[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    load[0].push_back(arr[0]);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && load[j].size() + 1 > load[i].size() + 1)
                load[i] = load[j];
        }
        load[i].push_back(arr[i]);
    }
    vector<int> max;
    for(int i = 0; i < n; i++)
        if(max.size() < load[i].size())
            max = load[i];
    for(int i = 0; i < max.size(); i++)
        cout << max[i] << " ";
}

void printLIS(int n){
    int arr[n], load[n];
    vector<int> listarr[n];

    memset(load, 1, sizeof(load));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        listarr[i].push_back(arr[i]);
    for(int i = 1; i < n; i++){
        int index = -1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && load[j] + 1 >= load[i]){
                load[i] = load[j] + 1;
                index = j;
            }
        }
        if(index != -1){
            for(int k = 0; k < listarr[index].size(); k++)
                listarr[i].push_back(listarr[index][k]);
        }
    }
    int max = INT_MIN, index;
    for(int i = 0; i < n; i++)
        if(max < load[i]){
            max = load[i];
            index = i;
        }
    for(int i = listarr[index].size() - 1; i >= 0; i--)
        cout << listarr[index][i] << " ";
}
