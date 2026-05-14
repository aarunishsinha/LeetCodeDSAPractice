class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (string& st : wordDict) {
            dict.insert(st);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 0; i<s.size(); i++) {
            string st = "";
            for (int j = i; j>= 0; j--) {
                st.insert(0, 1, s[j]);
                if (dict.count(st)) {
                    dp[i+1] = dp[i+1] || dp[j];
                }
                if (dp[i+1]) break;
            }
            // cout << dp[i+1] << " " << i << endl;
        }
        return dp[s.size()];
    }
};