class Solution {
private:
    int memo[1<<16];
public:
    bool createPartitions(vector<int>& nums, int mask, int k, int target, int currentSum, int start) {
        if (k == 0) 
        {
            return true;
        }
        if (currentSum == target) {
            return memo[mask] = createPartitions(nums, mask, k-1, target, 0, 0);
        }
        if (memo[mask] != -1) return memo[mask];
        for (int i = start; i < nums.size(); i++) {
            if (!(mask & (1 << i)) && currentSum + nums[i] <= target) {
                if (createPartitions(nums, mask | (1 << i), k, target, currentSum + nums[i], i+1)) {
                    return memo[mask] = 1;
                }
            }
        }
        return memo[mask] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        sort(nums.rbegin(), nums.rend());
        memset(memo, -1, sizeof(memo));
        return createPartitions(nums, 0, k, sum/k, 0, 0);
    }
};