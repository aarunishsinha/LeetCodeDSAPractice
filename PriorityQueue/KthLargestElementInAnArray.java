class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int val : nums) {
            if (minHeap.size() == k) {
                if (val > minHeap.peek()) {
                    minHeap.poll();
                    minHeap.offer(val);
                }
            }
            else {
                minHeap.offer(val);
            }
        }
        return minHeap.peek();
    }
}