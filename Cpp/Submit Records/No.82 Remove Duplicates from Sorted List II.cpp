/********************************************
作者:Alfeim
题目:删除排序链表的重复元素2
时间消耗:16ms
解题思路:链表问题使用虚头(dummy)能很直观地进行操作
相似题目：No.83 删除排序链表的重复元素
********************************************/
class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* last = dummy;
        ListNode* cur = head;
        while(cur != NULL){
            int curVal = cur->val;
            bool if_multi = (cur->next != NULL) && (cur->next->val == curVal);
            
            if(if_multi)
                for(cur = cur->next; cur != NULL && cur->val == curVal;cur = cur->next);
            else{
                last->next = cur;
                last = last->next;
                cur = cur->next;
            }
        }  
        if(last)
            last->next = NULL;
        
        return dummy->next; 
    }
};
