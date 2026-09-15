class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left =0, maxfreq = 0, result = 0;
        for(int right = 0; right < (int)s.size(); right++){
            count[s[right] - 'A']++;
            maxfreq = max(maxfreq, count[s[right] - 'A']);
            while((right-left+1) - maxfreq > k){
                count[s[left] - 'A']--;
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;
        

    }

};