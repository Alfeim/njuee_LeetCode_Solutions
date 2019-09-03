/********************************************
作者:Alfeim
题目:分隔链表
时间消耗:8ms
解题思路:见注释
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int len = 0;
        //计算链表的有效长度
        for(auto it = root ; it != nullptr ; it = it->next,++len);
        //通过有效长度与k可以算出每段平均最小长度 以及 多余长度
        int avg_len = len / k,more_len = len % k;
        //part_len用于存储每一段的最终长度,初始化值为平均最小长度
        vector<int> part_len(k,avg_len);
        //从头开始,直到多余长度用完前给当前段+1,由此保证题意限制
        for(int i = 0 ; i < more_len ;++i) part_len[i] += 1;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = root;
        //然后开始遍历链表
        for(int i = 0; i < k ; ++i){
            int count = 0;
            auto it = dummy->next;
            while(it && count < part_len[i]){
                count++;
                if(count < part_len[i])it = it->next;
            }
            ListNode* cur = dummy->next;
            if(it)dummy->next = it->next,it->next = nullptr;
            else dummy->next = nullptr;
            res.push_back(cur);
        }
        
        return res;
        
    }
};
