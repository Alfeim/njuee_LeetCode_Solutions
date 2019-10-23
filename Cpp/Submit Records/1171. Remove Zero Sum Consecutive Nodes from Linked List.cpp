/********************************************
作者:Alfeim
题目:从链表中删去和为0的结点
时间消耗:16ms
解题思路:
利用前缀和的性质，从头开始遍历

用一个栈保存“合法”的结点

如果出现了重复的前缀和 说明上一个前缀和对应的下标 到当前下标为止区间的和就是0 那么就依次出栈

注意，初始时要有一个前缀和为0的记录
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        deque<ListNode*> D;
        unordered_set<int> SumRecord;
        SumRecord.insert(0);
        int Sum = 0;
        while(head != nullptr){
            Sum += head->val;
            ListNode *next = head->next;
            head->next = nullptr;
            D.push_back(head);

            if(SumRecord.count(Sum)){
                int last = Sum;
                Sum -= D.back()->val;
                D.pop_back();
                while(!D.empty() && Sum != last){
                    SumRecord.erase(Sum);
                    Sum -= D.back()->val;
                    D.pop_back();
                }
            }else{
                 SumRecord.insert(Sum);
            }

            head = next;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        dummy->next = nullptr;

        while(!D.empty()){
            cur->next = D.front();
            D.pop_front();
            cur = cur->next;
        }

        return dummy->next;

    }
};
