class LRUCache {
public:
    class node{
        public:
        
        int key;
        int value;
        node* next;
        node* prev;
        
        node(int _key,int _val){
            key = _key;
            value = _val;
        }
    };
    
    int cap;
    unordered_map<int,node*>ump;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    void deletenode(node* cur){
        node* curnext = cur->prev;
        node* curprev = cur->next;
        
        curnext->next = cur->next;
        curprev->prev = cur->prev;
    }
    
    void addnode(node* cur){
        
        node* curnext = head->next;
        cur->next = head->next;
        cur->prev = head;
        head->next = cur;
        curnext->prev = cur;
        
    }
    
    LRUCache(int capacity) {
        
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        
        if(ump.find(key) != ump.end()){
            
            node* temp = ump[key];
            deletenode(temp);
            addnode(temp);
            ump[key] = head->next;
            return head->next->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(ump.find(key) != ump.end()){
            
            node* temp = ump[key];
            deletenode(temp);
            ump.erase(key);
        }
        
        if(ump.size() == cap){
            ump.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        ump[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */