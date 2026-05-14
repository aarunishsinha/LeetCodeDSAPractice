# Pattern: Two Pointers

This directory serves as an execution ledger for problems solved using the Two Pointer pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/?q=Trapping+rain+water) | 30m logic<br>30m total | **Pattern:** Two Pointers<br>**Trigger:** "trapped water an `i` is dependent on left and right boundary" | **Time:** `O(n)`<br>**Space:** `O(1)` | Water trapped an index `i` only depends on the smaller of `leftMax` and `rightMax` | Edge elements will never store an water |
| 2 | [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | 3m logic<br>14m total | **Pattern:** Sliding Window<br>**Trigger:** "Longest substring without duplicate characters" | **Time:** `O(n)`<br>**Space:** `O(1)` | Move from left to right, keep expanding the window as long as you see no duplicates and keep track of the last index where you saw a certain character. If you see a duplicate and it is within the window move the left boundary of the window right after the position where the character was last seen | -- |