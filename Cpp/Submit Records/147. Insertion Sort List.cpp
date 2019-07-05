/********************************************
作者:Alfeim
题目:对链表进行插入排序
时间消耗:28ms
解题思路:模拟插入排序,不过每次重新插入不是倒序遍历而是顺序遍历
********************************************/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = head;
        ListNode *cur = head->next;
        dummy->next = head;
        
        while(cur){
            //如果当前位置比上一位置大,则不需要重新插入，继续遍历链表
            if(cur->val > pre->val){
                pre = cur;
                cur = cur->next;
                continue;
            }
            //将当前节点从链表中移除
            pre->next = cur->next;
            cur->next = nullptr;
            
            //建立一个临时节点p
            ListNode *p = dummy;
            
            //寻址合适的位置
            for(;p != pre && cur->val > p->next->val ; p = p->next);
            
            cur->next = p->next;
            p->next = cur;
            cur = pre->next;
        }
        return dummy->next;
    }
};
