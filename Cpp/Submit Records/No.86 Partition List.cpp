/********************************************
作者:Alfeim
题目:分割链表
时间消耗:4ms
解题思路:链表、虚头、合并链表
********************************************/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *cur1 = dummy1;
        ListNode *cur2 = dummy2;
        while(head != NULL){
            ListNode *nextP = head->next;
            if(head->val < x){
                head->next = cur1->next;
                cur1->next = head;
                cur1 = cur1->next;
            }else{
                head->next = cur2->next;
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = nextP;
        }
        cur1->next = dummy2->next;
        return dummy1->next;
   
    }
};
