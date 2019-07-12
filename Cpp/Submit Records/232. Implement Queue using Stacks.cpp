/********************************************
作者:Alfeim
题目:用队列实现栈
时间消耗:4ms
解题思路:用两个队列来模拟即可
********************************************/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue():Queue_number(1){
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(S1.empty() && S2.empty()){
            if(Queue_number == 1)
                S1.push(x);
            else
                S2.push(x);
        }else if(Queue_number == 1){
            S2.push(x);
        }else if(Queue_number == 2){
            S1.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int cur;
        if(Queue_number == 1){
            cur = S1.top();
            S1.pop();
            while(S2.size() > 1){
                auto tmp = S2.top();
                S1.push(tmp);
                S2.pop();
            }
            Queue_number = 2;
        }else{
            cur = S2.top();
            S2.pop();
            while(S1.size() > 1){
                auto tmp = S1.top();
                S2.push(tmp);
                S1.pop();
            }
            Queue_number = 1;  
        }
        return cur;
    }
    
    /** Get the front element. */
    int peek() {
        return Queue_number  == 1 ? S1.top() : S2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return Queue_number == 1 ? S1.empty() : S2.empty();
    }
    
    int Queue_number;
    stack<int> S1;
    stack<int> S2;
    
};
