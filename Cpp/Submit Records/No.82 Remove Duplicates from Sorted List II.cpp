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
