class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res;
        int l, count;

        if(words.empty())
            return res;
        l = words[0].length();
        for(int i = 0; i < s.length(); i++){
            count = 0;
            unordered_map<string, int> um;
            for(int i = 0; i < words.size(); i++)
                um[words[i]]++;
            for(int j = i; count < words.size(); j = j + l){
                string temp = s.substr(j, l);
                if(um.find(temp) != um.end() && um[temp] != 0){
                    count++;
                    um[temp]--;
                }
                else
                    break;
            }
            if(count == words.size())
                res.push_back(i);
        }
        return res;
    }
};
