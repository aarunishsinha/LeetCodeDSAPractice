class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];
        for (char ch : tasks) {
            freq[ch-'A']++;
        }
        int maxFreq = 0;
        int maxFreqCount = 0;
        for (int i = 0; i<26; i++) {
            if (maxFreq<freq[i]) {
                maxFreq = freq[i];
                maxFreqCount = 1;
            }
            else if (maxFreq == freq[i]) {
                maxFreqCount++;
            }
        }
        int intervals = (maxFreq-1)*(n+1) + maxFreqCount;
        return Math.max(intervals, tasks.length);
    }
}