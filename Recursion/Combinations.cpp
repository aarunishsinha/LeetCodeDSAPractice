class Solution {
public:
    void createCombs(vector<int>& nums, vector<vector<int>>& res, int idx, vector<int>& comb, int& k) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }
        else if (comb.size() > k) {
            return;
        }
        else {
            for (int j = idx; j<nums.size(); j++) {
                comb.push_back(nums[j]);
                createCombs(nums, res, j+1, comb, k);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res = {};
        vector<int> comb = {};
        vector<int> nums(n, 0);
        iota(nums.begin(), nums.end(), 1);
        createCombs(nums, res, 0, comb, k);
        return res;
    }
};