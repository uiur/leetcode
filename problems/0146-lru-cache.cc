class LRUCache {
public:
    list<int> keys;
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> pos;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        touch(key);
        return m[key];
    }
    
    void put(int key, int value) {
        m[key] = value;
        
        touch(key);
        if (keys.size() > cap) {
            int old = keys.front();
            keys.pop_front();
            m.erase(old);
            pos.erase(old);
        }
    }
    
    void touch(int key) {
        if (pos.find(key) != pos.end()) keys.erase(pos[key]);
        keys.push_back(key);
        list<int>::iterator last = keys.end();
        last--;
        pos[key] = last;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
