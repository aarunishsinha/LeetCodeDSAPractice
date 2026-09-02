# Pattern: Bitwise

This directory serves as an execution ledger for problems solved using the Bitwise pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [136. Single Number](https://leetcode.com/problems/single-number/) | 1m logic<br> 2m total | **Pattern:** XOR <br>**Trigger:** "All numbers occur twice and only one occurs once" | **Time:** `O(n)`<br>**Space:** `O(1)` | XOR of two same numbers is 0, so take XOR of the whole array and only the number occuring onces will remain | For a single element array that element is the answer |
| 1 | [137. Single Number II](https://leetcode.com/problems/single-number-ii/) | 15m logic<br> 20m total | **Pattern:** Bit manipulation <br>**Trigger:** "All numbers occur thrice and only one occurs once" | **Time:** `O(n)`<br>**Space:** `O(1)` | For 32-bit integers, since each number appears thrice, sums of the number of times a bit is 1 should be divisible by 3. If that is not the case then that bit is set for the number that appears only once | For a single element array that element is the answer |