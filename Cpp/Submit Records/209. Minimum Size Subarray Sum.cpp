/********************************************
作者:Alfeim
题目:长度最小的子数组
时间消耗:8ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {  
        int left = 0,right = -1;
        int n = nums.size();
        int res = n + 1;
        int sum = 0;
        while(left <n && right < n){       
           if(sum < s){
               right++; 
               if(right >= n)
                   break;
               sum += nums[right];
           }else{
               res = min(res,right-left + 1); 
               sum -= nums[left];
               left++;
           }

        }  
        return res == n + 1 ? 0 : res;  
    }
};

