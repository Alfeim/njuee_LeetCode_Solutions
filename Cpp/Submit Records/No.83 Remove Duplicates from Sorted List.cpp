/********************************************
作者:Alfeim
题目:删除排序链表的重复元素
时间消耗:16ms
解题思路:链表、虚头
相似题目：No.82 删除排序链表的重复元素2
********************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *last = dummy;
        ListNode *cur = head;
        while(cur != nullptr){
            int curVal = cur->val;      
            while(cur->next != nullptr && cur->next->val == curVal)
                cur = cur->next; 
            last->next = cur;
            last = last->next; 
            cur = cur->next;
        } 
        return dummy->next;
    }
};
