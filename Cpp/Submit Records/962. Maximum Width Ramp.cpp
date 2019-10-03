/********************************************
作者:Alfeim
题目:最大坡宽度
时间消耗:60ms
解题思路:单调栈
********************************************/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> S;
        int n = A.size();
        int res = 0;
        int tmp = 0;
        
        for(int i = 0 ; i < n ; ++i){
            if(S.empty() || A[i] <= A[S.top()]) S.push(i);
        }
        
        
        for(int i = n - 1 ; i > 0 && !S.empty() ;--i){    
            
            tmp = i;
            
            while(!S.empty() && A[S.top()] <= A[i]){
                tmp = S.top();
                S.pop();
            }
            
            res = max(res,i - tmp);
            
        } 
        
        return res;
    }
};
