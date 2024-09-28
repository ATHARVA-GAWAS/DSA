class MyCircularDeque {
public:
    vector<int>dq;
    int capacity, front = 0, count = 0, back = 0;
    MyCircularDeque(int k) {
        dq.resize(k);
        capacity = k;
        front = k - 1;
    }
    
    bool insertFront(int value) {
        if (count >= capacity)
            return false;
        count++;
        dq[front] = value;
        front = (front - 1 + capacity) % capacity;
        return true;
    }
    
    bool insertLast(int value) {
        if (count >= capacity)
            return false;
        count++;
        dq[back] = value;
        back = (back + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if (count == 0) 
            return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (count == 0)
            return false;
        back = (back - 1 + capacity) % capacity; //-- to ensure it goes on values [0, capacity]
        count--;
        return true;
    }
    
    int getFront() {
        if (count == 0)
            return -1;
        return dq[(front + 1) % capacity];
    }
    
    int getRear() {
        if(count == 0)
            return -1;
        return dq[(back - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */