/********************************************
作者:Alfeim
题目:重排链表
时间消耗:100ms/60ms
解题思路:链表、翻转/栈、双向队列
********************************************/

解法1:借助栈(100ms)
class Solution {
public:
    stack<ListNode*> S;
    queue<ListNode*> Q;
    void reorderList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int Length = 0;
        int tmpLen = 0;
        for(;head != nullptr ; head = head->next){
            S.push(head);
            Q.push(head);
            Length++;
        }
 
        while(!S.empty() && !Q.empty() && tmpLen < Length){
            auto p1 = Q.front();
            auto p2 = S.top();
            
            if(p1 == p2){
                p1->next = cur->next;
                cur->next = p1;
                break;
            }
            
            p1->next = cur->next;
            cur->next = p1;
            cur = cur->next;
            
            p2->next = cur->next;
            cur->next = p2;
            cur = cur->next;
            
            Q.pop();
            S.pop();
            
            tmpLen += 2;
            
        }
        
        return;
    }
};

解法2:不借助栈(60ms)
class Solution {
public:

    void reorderList(ListNode* head) {
        if(!head)
            return;
        
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *dummy3 = new ListNode(-1);
        ListNode *slow = head,*fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        dummy1->next = head;
        ListNode *p = slow->next;
        slow->next = nullptr; 
        
        //先翻转第二条链表
        while(p){
            ListNode *pnext = p->next;
            p->next = dummy2->next;
            dummy2->next = p;
            p = pnext;
        }
        
       
        ListNode *cur1 = dummy1->next,*cur2 = dummy2->next,*cur3 = dummy3;
        
        while(cur1 && cur2){
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;
            
            cur1->next = cur3->next;
            cur3->next = cur1;
            cur3 = cur3->next;
            
            cur2->next = cur3->next;
            cur3->next = cur2;
            cur3 = cur3->next;
            
            cur1 = next1;
            cur2 = next2;
        }
        
        if(cur1){
            cur1->next = cur3->next;
            cur3->next = cur1;
        }
        return;
    }
};
