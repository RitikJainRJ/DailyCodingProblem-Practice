#include<bits/stdc++.h>
using namespace std;

bool onLine(vector<int> &p, vector<int> &q, vector<int> &r){
    return min(p[0], q[0]) <= r[0] && r[0] <= max(p[0], q[0])
            && min(p[1], q[1]) <= r[1] && r[1] <= max(p[1], q[1]);
}

int crossProd(vector<int> &p, vector<int> &q, vector<int> &r){
    int res = (p[0] - q[0]) * (p[1] - r[1]) - (p[1] - q[1]) * (p[0] - r[0]);
    if(res == 0)
        return 0;
    return res > 0 ? 1 : -1;
}

bool isIntersect(vector<int> &p, vector<int> &q, vector<int> &r, vector<int> s){
    int o1 = crossProd(p, q, r);
    int o2 = crossProd(p, q, s);
    int o3 = crossProd(r, s, p);
    int o4 = crossProd(r, s, q);

    if(o1 != o2 && o3 != o4)
        return true;
    if(o1 == 0 && onLine(p, q, r))  return true;
    if(o2 == 0 && onLine(p, q, s))  return true;
    if(o3 == 0 && onLine(r, s, p))  return true;
    if(o4 == 0 && onLine(r, s, q))  return true;
    return false;
}

bool isInside(vector<vector<int>> &vec, vector<int> &point){
    int n = vec.size();
    int i = 0, count = 0;

    do{
        if(isIntersect(vec[i], vec[(i + 1) % n], point, {INT_MAX, point[1]})){
            if(crossProd(vec[i], vec[(i + 1) % n], point) == 0)
                return onLine(vec[i], vec[(i + 1) % n], point);
            count++;
        }
        i++;
    }while(i < n);
    return count % 2;
}

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> vec(n, vector<int>(2));
        vector<int> point(2);

        for(int i = 0; i < n; i++)
            cin >> vec[i][0] >> vec[i][1];
        cin >> point[0] >> point[1];
        cout << isInside(vec, point) << endl;
    }
    return 0;
}
