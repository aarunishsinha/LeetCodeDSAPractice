class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> numCoins(amount+1, INT_MAX);
        numCoins[0] = 0;
        for (long long i = 0; i<=amount; i++) {
            if (numCoins[i] == INT_MAX) continue;
            for (int coin : coins) {
                if (i + coin <= amount) {
                    numCoins[i+coin] = min(numCoins[i+coin], numCoins[i]+1);
                }
                else {
                    break;
                }
            }
        }
        return numCoins[amount] == INT_MAX ? -1 : numCoins[amount];
    }
};

/*
TOP-DOWN APPROACH
class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& numCoins) {
        if (amount == 0) {
            return 0;
        }
        else if (amount < 0) {
            return INT_MAX;
        }
        if (numCoins[amount] != -1) {
            return numCoins[amount];
        }
        numCoins[amount] = INT_MAX;
        for (int& coin : coins) {
            int val = solve(coins, amount-coin, numCoins);
            if (val != INT_MAX) {
                numCoins[amount] = min(numCoins[amount], val+1);
            }
        }
        return numCoins[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numCoins(amount+1, -1);
        numCoins[0] = 0;
        sort(coins.rbegin(), coins.rend());
        int res = solve(coins, amount, numCoins);
        return res == INT_MAX ? -1 : res;
    }
};
*/