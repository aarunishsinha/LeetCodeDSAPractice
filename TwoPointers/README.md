# Pattern: Two Pointers

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/?q=Trapping+rain+water) | 30m logic<br>30m total | **Pattern:** Two Pointers<br>**Trigger:** "trapped water an `i` is dependent on left and right boundary" | **Time:** `O(n)`<br>**Space:** `O(1)` | Water trapped an index `i` only depends on the smaller of `leftMax` and `rightMax` | Edge elements will never store an water |