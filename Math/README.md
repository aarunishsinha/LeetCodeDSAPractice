# Pattern: Math

This directory serves as an execution ledger for problems solved using the Math. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/) | 5m logic<br>20m total | **Pattern:** Reverse String<br>**Trigger:** "Check palindrome without converting to string" | **Time:** `O(n)`<br>**Space:** `O(1)` | Reverse half of the integer and check if it mirrors, reversing the whole integer can lead to overflow | -- |
| 2 | [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/) | 15m logic<br> 20m total | **Pattern:** Math <br>**Trigger:** "" | **Time:** `O(n)`<br>**Space:** `O(1)` | You can calculate the exact number of slots this "Boss structure" requires using basic math: Number of full chunks: `(maxFrequency - 1)`, Size of each chunk: `(n + 1)`. You just add the count of these max-frequency tasks to the end. `Total Time = (maxFrequency - 1) * (n + 1) + (count of max frequency tasks)` | No tasks means no CPU intervals needed |