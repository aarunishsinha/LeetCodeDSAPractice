class Solution {
public:
    void createComb(vector<int>& nums, vector<vector<int>>& res, int start, vector<int>& comb) {
        res.push_back(comb);
        unordered_set<int> s;
        for (int i = start; i < nums.size(); i++) {
            if (s.count(nums[i]) == 0) {
                comb.push_back(nums[i]);
                createComb(nums, res, i+1, comb);
                comb.pop_back();
                s.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> comb;
        createComb(nums, res, 0, comb);
        return res;
    }
};