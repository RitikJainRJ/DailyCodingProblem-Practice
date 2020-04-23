vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    multimap<int, pair<int, int>> om;

    for(int i = 0; i < points.size(); i++){
        int a = points[i][0], b = points[i][1];
        int c = a * a + b * b;
        om.insert({c, {a, b}});
    }
    points.clear();
    for(auto it = om.begin(); it != om.end() && K > 0; it++, K--){
        vector<int> temp;
        temp.push_back(it->second.first);
        temp.push_back(it->second.second);
        points.push_back(temp);
    }
    return points;
}
