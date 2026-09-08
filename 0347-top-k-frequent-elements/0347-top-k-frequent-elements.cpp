class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for(int n : nums){
            freq[n]++;
        }
        int n = nums.size();
        vector<vector<int>>buckets(n+1);
        for(auto& [num , count] : freq){
            buckets[count].push_back(num);
        }
        vector<int> result;
        for(int i = n; i >= 0 && result.size() < (size_t)k; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == (size_t)k){
                    break;
                }
            }
        }
        return result;
    }
};