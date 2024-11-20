class LRUCache {
public:

    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> m;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newnode){
        Node* currHeadNextNode = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = currHeadNextNode;
        currHeadNextNode->prev = newnode;
    }

    void deleteNode(Node* node){
        Node* prevv = node->prev;
        Node* nextt = node->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    LRUCache(int capacity) {
        cap = capacity;
        m.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* node = m[key];
        deleteNode(node);
        addNode(node);
        m.erase(key);
        m[key] = head->next;
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            m.erase(key);
            m[key] = head->next;
        }else{
            Node* node = new Node(key, value);
            if(m.size()==cap){
                m.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addNode(node);
            m[key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */