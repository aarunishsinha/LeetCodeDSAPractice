struct TrieNode {
    bool isEnd = false;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
};
class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children[ch-'a']==nullptr) {
                node->children[ch-'a'] = new TrieNode;
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchUtil(0, word, node);
    }

    bool searchUtil(int idx, string& word, TrieNode* node) {
        if (idx==word.size()) {
            return node->isEnd;
        }
        if (word[idx]=='.') {
            bool res = false;
            for (int i = 0; i<26; i++) {
                if (node->children[i] != nullptr) {
                    res = res | searchUtil(idx+1, word, node->children[i]);
                }
                if (res) break;
            }
            return res;
        }
        else {
            if (node->children[word[idx]-'a'])
                return searchUtil(idx+1, word, node->children[word[idx]-'a']);
            else return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */