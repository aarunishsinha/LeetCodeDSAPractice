class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        int idx = 0, n = nums.size();
        arr.push_back(nums[0]);
        for (int i = 1; i<n; i++) {
            if (nums[i] <= arr[idx]) {
                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
                *it = nums[i];
            }
            else {
                arr.push_back(nums[i]);
                idx++;
            }
        }
        return arr.size();
    }
};