/********************************************
作者:Alfeim
题目:使数组唯一的最小增量
时间消耗:80ms
解题思路:贪心
********************************************/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        
        int res = 0,
            last = -1,
            n = A.size();
        
        for(int i = 0 ; i < n ; ++i){
            
            if(A[i] <= last){
                res += (last + 1 - A[i]);   
                A[i] = last + 1;
            }
            
            last = A[i];
        }
        
        return res;
        
    }
};
