class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum %2 != 0) return false;
        int target = sum/2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int val : nums) {
            for (int i = sum; i>=0; i--) {
                if (dp[i] && i+val <= sum) {
                    dp[i+val] = true;
                }
            }
            if (dp[target]) return true;
        }
        return false;
    }
};