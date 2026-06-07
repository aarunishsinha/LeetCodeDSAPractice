class Solution {
    class TrieNode {
        public TrieNode one;
        public TrieNode zero;
        public TrieNode()
        {
            one = null;
            zero = null;
        }
    }
    class Trie {
        private TrieNode root;
        public Trie() {
            root = new TrieNode();
        }
        public void insert(int x) {
            TrieNode node = root;
            for (int i = 31; i>= 0; i--) {
                int bit = (x >> i) & 1;
                if (bit == 1) {
                    if (node.one == null) {
                        node.one = new TrieNode();
                    }
                    node = node.one;
                }
                else {
                    if (node.zero == null) {
                        node.zero = new TrieNode();
                    }
                    node = node.zero;
                }
            }       
        }
        public int maxXor(int val) {
            TrieNode node = root;
            int xor = 0;
            for (int i = 31; i>=0; i--) {
                int bit = (val >> i) & 1;
                xor = xor << 1;
                if (bit == 1) {
                    if (node.zero != null) {
                        xor = xor | 1;
                        node = node.zero;
                    }
                    else if (node.one != null) {
                        node = node.one;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (node.one != null) {
                        xor = xor | 1;
                        node = node.one;
                    }
                    else if (node.zero != null) {
                        node = node.zero;
                    }
                    else {
                        break;
                    }
                }
            }
            return xor;
        }
    }
    public int findMaximumXOR(int[] nums) {
        int n = nums.length;
        Trie t = new Trie();
        int maxXor = 0;
        for (int i = 0; i<n; i++) {
            int currXor = t.maxXor(nums[i]);
            maxXor = Math.max(currXor, maxXor);
            t.insert(nums[i]);
        }
        return maxXor;
    }
}