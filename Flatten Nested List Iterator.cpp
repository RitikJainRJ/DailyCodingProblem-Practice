class NestedIterator {
public:
    vector<int> res;
    int ind;

    void _flatten(vector<NestedInteger> &arr){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i].isInteger())
                res.push_back(arr[i].getInteger());
            else{
                _flatten(arr[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &arr) {
        _flatten(arr);
        ind = 0;
    }

    int next() {
        ind++;
        return(res[ind - 1]);
    }

    bool hasNext() {
        if(ind == res.size())
            return false;
        return true;
    }
};
