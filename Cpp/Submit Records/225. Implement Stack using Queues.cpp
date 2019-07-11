/********************************************
作者:Alfeim
题目:用队列实现栈
时间消耗:4ms
解题思路:用两个队列来模拟一个栈;其中一个队列来模拟“栈顶”,称作栈顶队,其永远只有一个元素,即栈顶

入栈操作:首先找到当前为“栈顶”的那个队列，将其唯一的元素弹出并入另一队，然后将要压入的元素入到“栈顶”队即可

出栈操作:记录栈顶队的元素值，然后将其唯一元素弹出。随后，将另一个队列的元素依次入到原“栈顶”队，直到另一个

队列只剩下唯一元素并将另一队列更新为新的“栈顶队列”,返回记录的值即可 

取栈顶元素：返回栈顶队列的首元素即可 

empty:返回栈顶队列的empty()即可
********************************************/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        curr_top = 1;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(Q1.empty() && Q2.empty()){
             if(curr_top == 1){
                 Q1.push(x);
                curr_top = 1;
             }else{
                 Q2.push(x);
                 curr_top = 2;
             }
 
        }else{
            if(curr_top == 1){
                auto last = Q1.front();
                Q1.pop();
                Q2.push(last);
                Q1.push(x);
            }else{
                auto last = Q2.front();
                Q2.pop();
                Q1.push(last);
                Q2.push(x);
            }
        }
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cur = 0;
        if(curr_top == 1){
            cur = Q1.front();
            Q1.pop();
            while(Q2.size() > 1){
                auto tmp = Q2.front();
                Q2.pop();
                Q1.push(tmp);
            }
            curr_top = 2;
            return cur;
        }else if(curr_top == 2){
            cur = Q2.front();
            Q2.pop();
            while(Q1.size() > 1){
                auto tmp = Q1.front();
                Q1.pop();
                Q2.push(tmp);
            }
            curr_top = 1;
        }
        
        return cur;
    }
    
    /** Get the top element. */
    int top() {
        return curr_top == 1 ? Q1.front() : Q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return curr_top == 1 ? Q1.empty() : Q2.empty();
    }
    
    int curr_top;
    queue<int> Q1;
    queue<int> Q2;
    
};
