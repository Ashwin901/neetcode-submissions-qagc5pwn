class LRUCache {
public:

    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v){
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
    int n;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> umap;

    LRUCache(int capacity) {
        n = capacity;
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;
        // move node to end of list
        moveNodeToEnd(umap[key]);
        return umap[key]->val;
    }

    void moveNodeToEnd(ListNode* node){
        // remove node from current position
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        // move node to end 
        ListNode* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
    }
    
    void put(int key, int value) {
        if(umap.find(key) == umap.end()){
            ListNode* newNode = new ListNode(key, value);
            if(umap.size() >= n){
                // delete node from head
                int nodeKey = head->next->key;
                head->next = head->next->next;
                head->next->prev = head;
                umap.erase(nodeKey);
            }
            // add node to tail
            ListNode* lastNode = tail->prev;
            lastNode->next = newNode;
            newNode->next = tail;
            newNode->prev = lastNode;
            tail->prev = newNode;

            umap[key] = newNode;
        } else {
            // update node value
            umap[key]->val = value;
            // move node to end of list
            moveNodeToEnd(umap[key]);
        }
    }
};
