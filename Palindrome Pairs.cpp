class Solution {
public:
    bool isPalindrome(string str){
        if(str.empty())
            return true;
        int n = str.length();
        for(int i = 0, j = n - 1; i < j; i++, j--){
            if(str[i] != str[j])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> um;
        int n = words.size();

        if(n < 2)
            return res;
        for(int i = 0; i < n; i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            um[temp] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= words[i].size(); j++){
                string s1 = words[i].substr(0, j);
                string s2 = words[i].substr(j);

                if(um.find(s1) != um.end() && um[s1] != i && isPalindrome(s2)){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(um[s1]);
                    res.push_back(temp);
                }

                if(!s1.empty() && um.find(s2) != um.end() && i != um[s2] && isPalindrome(s1)){
                    vector<int> temp;
                    temp.push_back(um[s2]);
                    temp.push_back(i);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
