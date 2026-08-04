class MyHashSet {

    vector<bool> vrednosti;

public:
    MyHashSet() {
        vrednosti = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        vrednosti[key] = true;
    }
    
    void remove(int key) {
        vrednosti[key] = false;
    }
    
    bool contains(int key) {
        return vrednosti[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */