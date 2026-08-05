class MyCircularQueue {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int capacity;
    int size;
    ListNode *front, *back;

public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->size = 0;
        this->front = this->back = nullptr;
    }
    
    bool enQueue(int value) {
        if(!front && size < capacity) {
            front = new ListNode(value);
            back = front;//ovo je ako je bio prazan red
            size++;
            return true;
        } else if(size < capacity){
            ListNode *novi = new ListNode(value);
            back->next = novi;
            back = novi;
            size++;
            return true;
        } else {
            return false;
        }
    }
    
    bool deQueue() {
        if(front) {
            if(front == back) {
                //ovo znaci da imamo 1 element samo u redu
                ListNode* curr = front;
                delete curr;
                front = back = nullptr;
                size--;
                return true;
            } else {
                ListNode* curr = front;
                front = front->next;
                delete curr;
                size--;
                return true;
            }
        } else {
            return false;
        }
    }
    
    int Front() {
        if(!front) {
            return -1;
        } else {
            return front->val;
        }
    }
    
    int Rear() {
        if(!back) {
            return -1;
        } else {
            return back->val;
        }
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */