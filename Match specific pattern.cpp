string convert(string);

vector<string> findMatchedWords(vector<string> dict, string pattern){
    vector<string> res;
    pattern = convert(pattern);
    for(int i = 0; i < dict.size(); i++){
        if(convert(dict[i]) == pattern)
            res.push_back(dict[i]);
    }
    return res;
}

string convert(string str){
    int count = 1;
    unordered_map<char, int> um;
    string res;

    for(int i = 0; i < str.length(); i++){
        if(um.find(str[i]) == um.end()){
            um[str[i]] = count;
            count++;
        }
    }
    for(int i = 0; i < str.length(); i++){
        char temp = um[str[i]] + '0';
        res = res + temp;
    }
    return res;
}
