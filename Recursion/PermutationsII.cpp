class Solution {
public:
    void create(vector<vector<int>>& res, vector<int>& nums, int& start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        unordered_set<int> uniqAtLevel;
        for (int i = start; i<nums.size(); i++) {
            if (uniqAtLevel.count(nums[i])) continue;
            uniqAtLevel.insert(nums[i]);
            swap(nums[start], nums[i]);
            start++;
            create(res, nums, start);
            start--;
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int start = 0;
        create(res, nums, start);
        return res;
    }
};