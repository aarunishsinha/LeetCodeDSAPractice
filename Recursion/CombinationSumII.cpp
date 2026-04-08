class Solution {
public:
    void createComb(vector<vector<int>> &res, vector<int> &nums, int target, vector<int> & comb, int start) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i<nums.size(); i++) {
            if (target >= nums[i]) {
                if (i > start && nums[i] == nums[i-1]) continue;
                comb.push_back(nums[i]);
                createComb(res, nums, target-nums[i], comb, i+1);
                comb.pop_back();
            }
            else {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        createComb(res, candidates, target, comb, 0);
        return res;
    }
};