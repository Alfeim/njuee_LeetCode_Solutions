/********************************************
作者:Alfeim
题目:反转链表2
时间消耗:4ms
解题思路:虚头、链表
********************************************/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *cur = head;
        ListNode* p = dummy1; //p用来记录第一段节点
        int i = 1;
        
        for(; cur != nullptr && i < m;i++){
            ListNode *cnext = cur->next;
            cur->next = p->next;
            p->next = cur;
            p = p->next;
            cur = cnext;
        }
        
        ListNode *q = cur;   //q用来记录翻转第一次翻转的节点
        for(;cur != nullptr && i <= n;i++){
            ListNode *cnext = cur->next;
            cur->next = dummy2->next;
            dummy2->next = cur;
            cur = cnext;
        }
        
        q->next = cur;
        p->next = dummy2->next;
        return dummy1->next;

    }
};
