/********************************************
作者:Alfeim
题目:设计链表
时间消耗:44ms
解题思路:双向链表的实现
********************************************/
class MyLinkedList {
public:
    struct myList{
        myList *prev;
        myList *next;
        int val;
        myList(int v):val(v),prev(this),next(this){};
    };
    
    /** Initialize your data structure here. */
    MyLinkedList():size(0){
        head = new myList(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size || index < 0) return -1;
        auto cur = head->next;
        for(int i = 0 ; i < index ; ++i) cur = cur->next;
    
        return cur->val;    
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto rlast = head->next;
        auto cur = new myList(val); 
        
        head->next = cur;
        rlast->prev = cur;
        cur->next = rlast;
        cur->prev = head;  
        
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto last = head->prev;
        auto cur = new myList(val);
        
        last->next = cur;
        head->prev = cur;
        cur->next = head;
        cur->prev = last;

        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        
        if(index < 0){
            addAtHead(val);
            return;
        }
            
        if(index == size) {
            addAtTail(val);
            return;
        }
        
        auto p = head->next;
        for(int i = 0 ; i < index ; ++i) p = p->next;
        auto last = p->prev;
        auto cur = new myList(val);
        
        last->next = cur;
        p->prev = cur;
        cur->next = p;
        cur->prev = last;
        
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;
        
        auto cur = head->next;
        for(int i = 0 ; i < index ; ++i) cur = cur->next;
        
        auto prev = cur->prev;
        auto next = cur->next;
        cur->prev = nullptr;
        cur->next = nullptr;
        
        prev->next = next;
        next->prev = prev;
        
        size--;
    }
    
private:
    myList *head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
