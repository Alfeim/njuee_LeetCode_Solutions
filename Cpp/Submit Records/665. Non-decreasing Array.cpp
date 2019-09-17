/********************************************
作者:Alfeim
题目:非递减序列
时间消耗:32ms
解题思路:没啥好说的..
********************************************/
class Solution {
public:

    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        
        for(int i = 1 ; i < n ; ++i){
            if(nums[i] < nums[i-1]){
                if(tmp >= 1) return false;
                
                if(i > 1 && nums[i-2] > nums[i]) nums[i] = nums[i-1];
                
                tmp++;
            }
        }
        
        return true;
       
    }
    
    
};
