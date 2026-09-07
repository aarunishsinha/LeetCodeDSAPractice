# Pattern: Matrices

This directory serves as an execution ledger for problems solved using the Matrices pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | 15m logic<br> 30m total | **Pattern:** Four Pointers <br>**Trigger:** "Traverse the matrix in a spiral" | **Time:** `O(m*n)`<br>**Space:** `O(1)` | Start with four pointers for the four boundaries of the matrix and traverse in the following order: `left -> right` on top, `top -> bottom` on right, `right -> left` on bottom and `bottom -> top` on left | If the matrix is empty then there are no elements in the spiral |