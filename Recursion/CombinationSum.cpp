class Solution {
public:
    void createComb(vector<int>& nums, vector<vector<int>>& res, int& target, int& sumSoFar, vector<int>& comb, int start) {
        if (sumSoFar == target) {
            res.push_back(comb);
            return ;
        }
        else if (sumSoFar > target) {
            return;
        }
        else {
            for (int i = start; i<nums.size(); i++) {
                comb.push_back(nums[i]);
                sumSoFar += nums[i];
                createComb(nums, res, target, sumSoFar, comb, i);
                sumSoFar -= nums[i];
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        int sumSoFar = 0;
        createComb(candidates, res, target, sumSoFar, comb, 0);
        return res;
    }
};