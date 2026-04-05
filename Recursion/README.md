# Pattern: Recursion

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [Example Problem Name](https://leetcode.com/...) | 12m logic<br>25m total | **Pattern:** Backtracking<br>**Trigger:** "Return all possible permutations" | **Time:** `O(N * N!)`<br>**Space:** `O(N)` | Forgot to remove the last element from the temporary array during the backtracking step, leading to duplicate states. | Empty array, duplicate elements |