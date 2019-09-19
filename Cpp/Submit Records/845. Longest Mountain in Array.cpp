/********************************************
作者:Alfeim
题目:数组中的最长山脉
时间消耗:28ms
解题思路:记录一下每个节点左右的递减序列各有多长即可
********************************************/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        bool mountain = false;
        int res = 0;
        
        int n = A.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i = 1 ,tmp = 0; i < n ; ++i){
            if(A[i] > A[i-1]) tmp++;
            else tmp = 0;
            left[i] = tmp;
        }
        
        
        for(int i = n - 2,tmp = 0; i >= 0 ; --i){
            if(A[i] > A[i+1]) tmp++;
            else tmp = 0;
            right[i] = tmp;
        }
        

        for(int i = 0 ; i < n ; ++i){
            if(left[i] > 0 && right[i] > 0 && left[i] + right[i] >= 2){
                res = max(left[i] + right[i] + 1,res);
            }
        }
        
        return res;
        
        
    }
};
