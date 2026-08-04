class MyHashMap {

    vector<int> vrednosti;//ako nema vrednosti nikakve samo cemo ostaviti -1

public:
    MyHashMap() {
        vrednosti = vector<int>(1000001, -1);
    }
    
    void put(int key, int value) {
        vrednosti[key] = value;
    }
    
    int get(int key) {
        return vrednosti[key];
    }
    
    void remove(int key) {
        vrednosti[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */