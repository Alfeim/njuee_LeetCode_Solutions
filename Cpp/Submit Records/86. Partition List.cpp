/********************************************
作者:Alfeim
题目:分割链表
时间消耗:4ms
解题思路:链表、虚头,用一个链表存储比x小的结点，另一个存储比x大的结点，最后合并即可；
注意这里的存储操作实际是插入，用cur记录当前链表的最后一个元素，其next指向nullptr，
存储原链表的结点实际是进行了插入操作，即用原链表的结点指向cur的下一元素(null)，然后
让cur指向该结点即可
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
