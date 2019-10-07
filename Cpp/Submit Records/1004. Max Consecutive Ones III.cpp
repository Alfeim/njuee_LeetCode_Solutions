/********************************************
作者:Alfeim
题目:最大连续1的个数3
时间消耗:60ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0 , n = A.size();
        int left = 0 , right = -1;
        int k = K;
        
        while(left < n && right < n){
            
            if(right < left) right = left;
            
            while(right < n){
                if(A[right] == 0){
                    if(k == 0) break;
                    k--;
                } 
                right++;
            }
            
            res = max(res,right - left);
            
            while(k <= 0 && left < right){
                if(A[left++] == 0) k++;  
            } 
            
            if(left == right) left = right + 1;
            
        }
        
        return res;
        
    }
};
