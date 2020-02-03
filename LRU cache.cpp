
class LRUCache{
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> um;
    int cap;

public:
    LRUCache(int cap) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        this->cap = cap;
    }

    int get(int key) {
        if(um.find(key) == um.end())
            return -1;
        int value = um[key]->second;
        dq.erase(um[key]);
        um.erase(key);
        dq.push_front({key, value});
        um[key] = dq.begin();
        return value;
    }

    void put(int key, int value) {
        if(um.find(key) != um.end()){
            dq.erase(um[key]);
            um.erase(key);
        }
        if(dq.size() < cap){
            dq.push_front({key, value});
            um[key] = dq.begin();
        }
        else{
            int temp = dq.back().first;
            dq.erase(um[temp]);
            um.erase(temp);
            dq.push_front({key, value});
            um[key] = dq.begin();
        }
    }
};
