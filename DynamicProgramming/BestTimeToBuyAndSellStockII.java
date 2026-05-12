class Solution {
    public int maxProfit(int[] prices) {
        int buy = (int)-1e7;
        int sell = 0;
        for (int i = 0; i<prices.length; i++) {
            int tempSell = sell;
            sell = Math.max(buy + prices[i], sell);
            buy = Math.max(buy, tempSell - prices[i]);
        }
        return sell;
    }
}