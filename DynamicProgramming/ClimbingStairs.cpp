class Solution {
private:
    int oneStep = 1, twoStep = 1;
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        for (int i = 2; i<=n; i++ ){
            int temp = oneStep;
            oneStep += twoStep;
            twoStep = temp;
        }
        return oneStep;
    }
};