# Pattern: Binary Search

This directory serves as an execution ledger for problems solved using the Binary Search pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/) | 2m logic<br> 6m total | **Pattern:** LIS Binary Search <br>**Trigger:** "Longest strictly increasing subsequence" | **Time:** `O(n*logn)`<br>**Space:** `O(n)` | Add element to array if it is greater than the last element, if not, find the next larger or equal number in the array and replace it. The size of the array never reduces and hence keeping track of the longest sequence seen so far | You will always have a subsequence of size 1 |