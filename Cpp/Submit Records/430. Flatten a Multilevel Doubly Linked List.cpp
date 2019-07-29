/********************************************
作者:Alfeim
题目:扁平化多级双向链表
时间消耗:140ms
解题思路:递归、实际上就是二叉树的先序遍历
********************************************/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* dummy = new Node(-1,NULL,head,NULL);
        Solve(head);
        return dummy->next;
    }
    
    Node* Solve(Node* cur){
        if(!cur)
            return NULL;
        
        if(!cur->next && !cur->child)
            return cur;
        
        auto nextcur = cur->next;
        auto child = cur->child;
        cur->next = NULL;
        cur->child = NULL;
        
        if(child){
            cur->next = child;
            child->prev = cur;
            cur = Solve(child);                
        }
        
        if(nextcur){
            cur->next = nextcur;
            nextcur->prev = cur;
            cur = Solve(nextcur);
        }
        
        return cur;
    }
 
};
