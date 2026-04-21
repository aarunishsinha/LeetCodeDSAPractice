class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost1 = cost[0], cost2 = cost[1];
        for (int i = 2; i<cost.size(); i++) {
            int temp = cost2;
            cost2 = min(cost1, cost2) + cost[i];
            cost1 = temp;
        }
        return min(cost1, cost2);
    }
};