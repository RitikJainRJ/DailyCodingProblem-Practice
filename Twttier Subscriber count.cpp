#include<bits/stdc++.h>
using namespace std;

void updateBIT(vector<int> &BIT, int ind, int val){
    ind++;

    while(ind < BIT.size()){
        BIT[ind] += val;
        ind += ind & -ind;
    }
}

int getSum(vector<int> &BIT, int ind){
    int res = 0;

    while(ind > 0){
        res += BIT[ind];
        ind -= ind & -ind;
    }
    return res;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(24);
        vector<int> BIT(24 + 1, 0);

        for(int i = 0; i < 24; i++)
            cin >> nums[i];
        for(int i = 0; i < 24; i++)
            updateBIT(BIT, i, nums[i]);
        for(int i = 0; i < 25; i++)
            cout << BIT[i] << " ";
        while(n--){
            int start, end;
            cin >> start >> end;
            cout << getSum(BIT, end) - getSum(BIT, start - 1) << endl;
        }
    }
    return 0;
}
