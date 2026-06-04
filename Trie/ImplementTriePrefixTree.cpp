class Trie {
public:
    class TrieNode {
    public:
        bool wordEnd = false;
        vector<TrieNode*> children;
    
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
        }
    };
    Trie() {
        root = new TrieNode();
    }

    TrieNode* root;
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new TrieNode();
            } 
            node = node->children[ch-'a'];
        }
        node->wordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a'] == nullptr) {
                return false;
            }
            node = node->children[ch-'a'];
        }
        if (node->wordEnd) {
            return true;
        }
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children[ch-'a'] == nullptr) {
                return false;
            }
            node = node->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */