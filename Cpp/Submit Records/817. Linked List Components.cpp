/********************************************
作者:Alfeim
题目:链表组件
时间消耗:72ms
解题思路:哈希表
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
    int numComponents(ListNode* head, vector<int>& G) {
        if(G.empty()) return 0;
        
        unordered_set<int> record;
        for(auto i : G) record.insert(i);
        
        auto cur = head;
        int res = 0;
        
        while(cur){
            if(!record.count(cur->val)){
                cur = cur->next;
                continue;
            }
            
            while(cur && record.count(cur->val) > 0) cur = cur->next;
            res += 1;
            if(cur) cur = cur->next;
        }
        return res;
    }
    
};
