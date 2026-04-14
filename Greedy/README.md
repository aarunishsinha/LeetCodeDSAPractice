# Pattern: Greedy

This directory serves as an execution ledger for problems solved using the Recursion pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | 3m logic<br>11m total | **Pattern:** Greedy State reset<br>**Trigger:** "Max profit in one transaction" | **Time:** `O(n)`<br>**Space:** `O(1)` | Maximum profit on any day is the price on that day minus the lowest price seen on a day before. The chronological ordering allows you to keep track of minimum past price(state) | If there is no profitable day then don't buy or sell, keeping profit 0 |