/********************************************
作者:Alfeim
题目:链表随机节点
时间消耗:88ms
解题思路:蓄水池抽样法,可以参考https://www.jianshu.com/p/7a9ea6ece2af
加入要从n个数中随机抽m个数，可以先把前m个元素放到“池子”里,然后继续遍历
元素,比如遍历到了的元素下标为i,则随机生成一个0-i之间的数字,如果该数字小于
m,就把池子里对应数字下标的元素替换成当前元素
********************************************/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *res = node;
        ListNode *cur = node->next;
        int pos = 2;
        while(cur != nullptr){
            int number = random()%pos;
            if(number == 0)
                res = cur;
            cur = cur->next;
            pos++;
        }
        return res->val;
    }
    
    ListNode* node;
};
