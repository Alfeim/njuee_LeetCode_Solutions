/********************************************
作者:Alfeim
题目:设计双端循环队列
时间消耗:80ms
解题思路:双向链表模拟双端队列
********************************************/
class MyCircularDeque {
public:
    struct DList{
        DList *prev;
        DList *next;
        int _val;
        DList(int val):_val(val){};
    };
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k):content(k),size(0){
        Head = new DList(-1);
        Head->prev = Head;
        Head->next = Head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size >= content) 
            return false;
        
        DList *cur = Head->next;
        DList *Node = new DList(value);
        Head->next = Node;
        cur->prev = Node;
        Node->prev = Head;
        Node->next = cur;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size >= content) 
            return false;
        
        DList *cur = Head->prev;
        DList *Node = new DList(value);
        cur->next = Node;
        Head->prev = Node;
        Node->prev = cur;
        Node->next = Head;
        size++;
        return true;
        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0) 
            return false;
        
        DList *cur = Head->next->next;
        Head->next->next = nullptr;
        Head->next->prev = nullptr;
        Head->next = cur;
        cur->prev = Head;
        size--;
        return true;
    } 
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0) 
            return false;
        
        DList *cur = Head->prev->prev;
        Head->prev->next = nullptr;
        Head->prev->prev = nullptr;
        cur->next = Head;
        Head->prev = cur;
        size--;
        return true;
        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return Head->next->_val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return Head->prev->_val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == content;
    }

private:
    int content;
    DList *Head;
    int size;
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
