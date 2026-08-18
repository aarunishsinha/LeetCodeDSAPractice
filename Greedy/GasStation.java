class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        // prelim check
        int costSum = 0, gasSum = 0;
        for (int i = 0; i<gas.length; i++) {
            costSum += cost[i];
            gasSum += gas[i];
        }
        if (costSum > gasSum) {
            return -1;
        }
        int tank = 0;
        int idx = 0;
        for (int i = 0; i<gas.length; i++) {
            int diff = gas[i] - cost[i];
            if (diff + tank >= 0) {
                tank += diff;
            }
            else {
                tank = 0;
                idx = i+1;
            }
        }
        return idx;
    }
}