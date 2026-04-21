class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> freq(1e4+1, 0);
        vector<int> dist;
        for (int i = 0; i<nums.size(); i++) {
            if (!freq[nums[i]]) {
                dist.push_back(nums[i]);
            }
            freq[nums[i]]++;
        }
        sort(dist.rbegin(), dist.rend());
        int take = dist[0]*freq[dist[0]];
        int dontTake = 0;
        for (int i = 1; i<dist.size(); i++) {
            int temp = dontTake;
            dontTake = max(take, dontTake);
            if (dist[i]+1 == dist[i-1]) {
                take = freq[dist[i]]*dist[i] + temp;
            }
            else {
                take = freq[dist[i]]*dist[i] + max(temp, take);
            }
        }
        return max(take, dontTake);
    }
};