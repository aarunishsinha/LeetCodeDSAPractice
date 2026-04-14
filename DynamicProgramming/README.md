# Pattern: Dynamic Programming

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | 14m logic<br>35m total | **Pattern:** Expand from the middle<br>**Trigger:** "Palindromic **substring**" | **Time:** `O(n^2)`<br>**Space:** `O(1)` | While this can be done using a 2D DP array to check palindrome in O(1) time getting a total time complexity of O(n^2) as well, it is practically slow due to space allocation. Since checking palidrome depends only one the boundary characters and if the string in middle is palindrome then you don't need the whole 2D DP array. Choose a center and expand from the middle until the substring is not a palindrome, and do this for all possible centers. Remember that even size strings have two centers unlike odd. | smallest palindromic substring is a character |