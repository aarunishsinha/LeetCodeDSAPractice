class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int curr1 = nums[0], prev1 = 0, prevprev1 = 0, curr2 = nums[1], prev2 = 0, prevprev2 = 0;
        for (int i = 1; i<n-1; i++) {
            int next1 = max(prev1, prevprev1) + nums[i];
            int next2 = max(prev2, prevprev2) + nums[i+1];
            prevprev1 = prev1;
            prevprev2 = prev2;
            prev1 = curr1;
            prev2 = curr2;
            curr1 = next1;
            curr2 = next2;
        }
        return max(max(curr1, prev1), max(curr2, prev2));
    }
};