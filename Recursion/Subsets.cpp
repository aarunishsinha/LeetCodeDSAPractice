class Solution {
public:
    void createSubsets(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);
        for (int j = idx; j<nums.size(); j++) {
            subset.push_back(nums[j]);
            createSubsets(nums, j+1, subset, res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset = {};
        createSubsets(nums, 0, subset, res);
        return res;
    }
};