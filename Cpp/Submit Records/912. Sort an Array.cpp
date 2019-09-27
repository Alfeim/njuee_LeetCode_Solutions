/********************************************
作者:Alfeim
题目:排序数组
时间消耗:110ms
解题思路:排序即可(个人实现为快排)
********************************************/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        Sort(nums,0,n-1);
        return nums;
    }
    
    void Sort(vector<int>& nums,int begin,int end){
        if(begin >= end) return;
        
        int j = begin,
            i = begin - 1;
        
        while(j <= end){
            if(nums[j] <= nums[end]){
                swap(nums[++i],nums[j]);   
            }
            j++;
        }
        
        Sort(nums,begin,i-1);
        Sort(nums,i+1,end);
        
    }
    
    
};
