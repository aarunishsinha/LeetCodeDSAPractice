# Pattern: Intervals

This directory serves as an execution ledger for problems solved using the Intervals pattern. 

> **The 15-Minute Rule:** If core logic is not cracked within 15 minutes, the problem is marked as a fail/review. 
> **Complexity Rule:** Time and Space complexity must be stated before coding.

## 📝 Problem Autopsy Ledger

| # | Problem & Link | Time | Pattern & Triggers | Complexity | The "Gotcha" / Bottleneck | Edge Cases |
| :--- | :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/) | 4m logic<br> 14m total | **Pattern:** Sort by Start <br>**Trigger:** "Merge Overlapping Intervals" | **Time:** `O(n*log(n))`<br>**Space:** `O(n)` | You need to merge intervals, hence sort by start. Merge intervals while iterating from left to right, if the start of the next interval is before the maximum end seen so far, merge it. | For a single element, the answer is that element |
| 2 | [57. Insert Interval](https://leetcode.com/problems/insert-interval/description/) | 3m logic<br> 31m total | **Pattern:** Sort by Start <br>**Trigger:** "Insert interval", "Merge overlapping intervals" | **Time:** `O(n)`<br>**Space:** `O(n)` | Since the intervals are already sorted by Start, you can do this in one pass. First find the last non-overlapping interval that comes before the new intervals and add those to the new intervals list. Next if necessary, merge the overlapping intervals with the new interval and add that to the new intervals list followed by the remaining non-overlapping intervals | If there are no intervals, just add newInterval |
| 3 | [435. Non-Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/) | 15m logic<br> 20m total | **Pattern:** Sort by End <br>**Trigger:** "Non-overlapping intervals", "remove overlapping intervals" | **Time:** addNum : `O(n*logn)`<br>**Space:** `O(1)` | Sorting by end time allows you to schedule with maximum intervals, which would mean that the intervals not used are the minimum number of overlapping intervals that need to be removed | For 1 interval, you don't need to remove anything |
