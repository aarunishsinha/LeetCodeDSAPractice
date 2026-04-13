class LRUCache {
public:
    class ListNode {
    public:
        int val = 0;
        int key = 0;
        ListNode* prev;
        ListNode* next;
        ListNode(int v, int k) {
            val = v;
            key = k;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    LRUCache(int capacity) {
        maxSize = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // Helper 1: Remove an existing node from the linked list
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Helper 2: Add a node right after the head (MRU position)
    void addToHead(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            ListNode* node = cache[key];
            // Promote to MRU
            removeNode(node);
            addToHead(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            // Key exists: update value and promote to MRU
            ListNode* node = cache[key];
            node->val = value;
            removeNode(node);
            addToHead(node);
        } 
        else {
            // Key doesn't exist
            if (currentSize == maxSize) {
                // Evict LRU node (node right before tail)
                ListNode* lruNode = tail->prev;
                cache.erase(lruNode->key);
                removeNode(lruNode);
                delete lruNode; // Good practice to free memory
                currentSize--;
            }
            
            // Add new node to the front (MRU position)
            ListNode* newNode = new ListNode(value, key);
            cache[key] = newNode;
            addToHead(newNode);
            currentSize++;
        }
    }

private:
    unordered_map<int, ListNode*> cache;
    int maxSize = 0;
    int currentSize = 0;
    ListNode *head, *tail;
};