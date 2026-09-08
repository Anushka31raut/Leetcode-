class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(const string& s : strs){
            int count[26] = {0};
            for(char c : s){
                count[c - 'a']++;
            }
            string key;
            for(int c : count){
                key += to_string(c) +'#';
            }
            map[key].push_back(s);
        }
        vector<vector<string>>result;
        for(auto& pair: map){
            result.push_back(move(pair.second));
        }
        return result;
    }
};