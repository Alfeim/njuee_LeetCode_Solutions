/********************************************
作者:Alfeim
题目:移除链表元素
时间消耗:36ms
解题思路:虚头、链表操作
********************************************/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = dummy->next;
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                cur->next = nullptr;
                cur = pre->next;
                continue;
            }
            pre = pre->next;
            cur = cur->next;
        } 
        return dummy->next;
    }
};
