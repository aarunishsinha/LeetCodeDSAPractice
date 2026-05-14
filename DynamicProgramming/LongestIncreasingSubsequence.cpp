class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1;
        int n = nums.size();
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for (int i = 1; i<n; i++) {
            int maxHere = 0;
            for (int j = i-1; j>=0; j--) {
                if (nums[j] < nums[i]) {
                    maxHere = max(maxHere, dp[j+1]);
                }
            }
            dp[i+1] = 1 + maxHere;
            maxLen = max(dp[i+1], maxLen);
        }
        return maxLen;
    }
};