class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(n+1, 0);
        for(int i = 0; i<n; i++) {
            prev[i+1] = i+1;
        }
        vector<int> curr(n+1, 0);
        for (int j = 0; j<m; j++) {
            curr[0] = j+1;
            for (int i = 0; i<n; i++) {
                if (word1[i] == word2[j]) {
                    curr[i+1] = prev[i];
                }
                else {
                    curr[i+1] = 1 + min(prev[i], min(curr[i], prev[i+1]));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};