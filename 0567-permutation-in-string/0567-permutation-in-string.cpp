class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;
        vector<int> need(26, 0), window(26, 0);
        for(char c : s1) need[c - 'a']++;
        for(int right = 0; right < n2; right++){
            window[s2[right] - 'a']++;
            int left = right - n1 + 1;
            if(left > 0){
                window[s2[left - 1] - 'a']--;
            }
            if(left >= 0 && window == need) return true;
        }
        return false;
    }
};