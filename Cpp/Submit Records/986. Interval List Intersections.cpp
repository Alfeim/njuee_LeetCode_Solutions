/********************************************
作者:Alfeim
题目:区间列表的交集
时间消耗:60ms
解题思路:
双指针
一个指针指向A种的区间，一个指向B中的区间

如果存在交集就填入res

如果当前A中指针对应的区间末尾 大于 B中指针对应的区间末尾 则右移动B指针(因为显然A中之后不会再有任何区间和当前B对应的区间有交集了)
否则 移动A指针
********************************************/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int m = A.size(),n = B.size();
        int begin = 0, end = 0;
        
        int i = 0,j = 0;
        while(i < n && j < m){
    
            begin = max(B[i][0],A[j][0]);
            end = min(B[i][1],A[j][1]);
            
            if(begin <= end) res.push_back({begin,end});
            
            if(A[j][1] > B[i][1]) i++;
            else j++;      
        
        }
        
        return res;
    }
};
