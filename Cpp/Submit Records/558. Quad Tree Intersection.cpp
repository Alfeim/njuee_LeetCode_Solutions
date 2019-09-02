
/********************************************
作者:Alfeim
题目:四叉树交集
时间消耗:476ms
解题思路:递归
********************************************/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree2->isLeaf){
            return quadTree1->val == true? quadTree1 : quadTree2;
        }
        
        if(!quadTree1->isLeaf && quadTree2->isLeaf){
            if(quadTree2->val) return quadTree2;
            return quadTree1;
        }
        
        if(quadTree1->isLeaf && !quadTree2->isLeaf){
            if(quadTree1->val) return quadTree1;
            return quadTree2;
        }
        
        quadTree1->topLeft = intersect(quadTree1->topLeft,quadTree2->topLeft);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
        quadTree1->topRight = intersect(quadTree1->topRight,quadTree2->topRight);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
        
        if(quadTree1->topLeft->isLeaf && quadTree1->bottomLeft->isLeaf &&  quadTree1->topRight->isLeaf && quadTree1->bottomRight->isLeaf){
            bool flag1 =  quadTree1->topLeft->val;
            bool flag2 =  quadTree1->topRight->val;
            bool flag3 =  quadTree1->bottomLeft->val;
            bool flag4 =  quadTree1->bottomRight->val;
            if(flag1 == flag2 && flag1 == flag3 && flag1 == flag4){
                quadTree1->isLeaf = true;
                quadTree1->topLeft = nullptr;
                quadTree1->topRight = nullptr;
                quadTree1->bottomLeft = nullptr;
                quadTree1->bottomRight = nullptr;
                quadTree1->val = flag1;
            }              
        }
        return quadTree1;
    }
};
