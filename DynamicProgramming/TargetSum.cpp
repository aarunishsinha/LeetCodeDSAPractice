class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(target) || (sum + target)%2 != 0) return 0;
        int newTarget = (sum + target) /2;
        vector<int> dp(newTarget+1, 0);
        dp[0]= 1;
        for (int val : nums) {
            for (int i = newTarget; i>= 0; i--) {
                if (i-val >= 0) {
                    dp[i] = dp[i] + dp[i-val];
                }
            }
        }
        return dp[newTarget];
    }
};