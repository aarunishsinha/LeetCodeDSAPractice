class Solution {
public:
    void createPerm(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm, vector<bool>& visited)
    {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i<nums.size(); i++) {
            if (visited[i] == false) {
                perm.push_back(nums[i]);
                visited[i] = true;
                createPerm(nums, res, perm, visited);
                visited[i] = false;
                perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> perm = {};
        vector<bool> visited(nums.size(), false);
        createPerm(nums, res, perm, visited);
        return res;
    }
};