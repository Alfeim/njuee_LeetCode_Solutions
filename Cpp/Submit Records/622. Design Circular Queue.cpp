/********************************************
作者:Alfeim
题目:设计循环队列
时间消耗:40ms
解题思路:双链表
********************************************/
class MyCircularQueue {
public:
    struct LoopList{
        LoopList *next;
        LoopList *prev;
        int _val;
        LoopList(int val):_val(val){}; 
    };
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k):content(k),size(0){
        head = new LoopList(-1);
        head->next = head;
        head->prev = head;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size >= content) 
            return false;
        LoopList *cur = new LoopList(value);
        LoopList *tail = head->prev;
        tail->next = cur;
        cur->next  = head;
        head->prev = cur;
        cur->prev  = tail;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size == 0) return false;
        LoopList *cur = head->next;
        LoopList *curnext  = cur->next;
        cur->prev = nullptr;
        cur->next = nullptr;
        head->next = curnext;
        curnext->prev = head;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return head->next->_val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return head->prev->_val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == content;
    }
    
    int content;
    int size;
    LoopList *head;
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
