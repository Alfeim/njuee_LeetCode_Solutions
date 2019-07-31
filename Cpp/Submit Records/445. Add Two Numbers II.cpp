/********************************************
作者:Alfeim
题目:两数相加
时间消耗:24ms
解题思路:链表
********************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    stack<int> val1;
    stack<int> val2;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1){
            val1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            val2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy->next;
        
        int carry = 0;
        while(!val1.empty() && !val2.empty()){
            int val = val1.top() + val2.top() + carry;
            carry = val/10;
            ListNode *node = new ListNode(val%10);
            node->next = cur;
            dummy->next = node;
            cur = dummy->next;
            val1.pop();
            val2.pop();
        }
        
        while(!val1.empty()){
            int val = val1.top() + carry;
            carry = val/10;
            ListNode *node = new ListNode(val%10);
            node->next = cur;
            dummy->next = node;
            cur = dummy->next;
            val1.pop();
        }
        
        while(!val2.empty()){
            int val = val2.top() + carry;
            carry = val/10;
            ListNode *node = new ListNode(val%10);
            node->next = cur;
            dummy->next = node;
            cur = dummy->next;
            val2.pop();
        }
        
        if(carry > 0){
            ListNode *node = new ListNode(1);
            node->next = cur;
            dummy->next = node;
            cur = dummy->next;
        }
        
        return dummy->next;
        
    }
};
