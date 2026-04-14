class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int maxLen = 0;
        int left = 0;
        for (int i = 0; i<s.size(); i++) {
            if (lastSeen[s[i]] >= left) {
                maxLen = max(maxLen, i-left);
                left = lastSeen[s[i]]+1;
                lastSeen[s[i]] = i;
            }
            else {
                lastSeen[s[i]] = i;
            }
        }
        maxLen = max(maxLen, ((int)s.size()-left));
        return maxLen;
    }
};