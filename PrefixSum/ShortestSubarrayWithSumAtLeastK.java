class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        int n = nums.length;
        int l = 0;
        int r = n-1;
        int shortestSize = -1;
        if (sum >= k) {
            shortestSize = n;
        }
        while (l <= r) {
            if (nums[l] > nums[r]) {
                sum -= nums[r];
                r--;
            }
            else {
                sum -= nums[l];
                l++;
            }
            if (sum >= k) {
                shortestSize = r-l+1;
            }
        }
        return shortestSize;
    }
}