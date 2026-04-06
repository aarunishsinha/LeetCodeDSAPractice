# Pattern: Recursion

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [78. Subsets](https://leetcode.com/problems/subsets/description/) | 5m logic<br>10m total | **Pattern:** Backtracking<br>**Trigger:** "Return all possible subsets" | **Time:** `O(N*2^N)`<br>**Space:** `O(N*2^N)` | Used more memory initially due to not passing current subset by reference, push_back() performs a deep-copy adding `O(N)` time in every recursive call, hence time complexity becomes `O(N*2^N)` | -- |