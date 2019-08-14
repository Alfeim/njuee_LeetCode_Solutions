/********************************************
作者:Alfeim
题目:翻转对
时间消耗:676ms
解题思路:归并
相似题目：315. Count of Smaller Numbers After Self
********************************************/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums,0,n);
        
    }
    
    int merge_sort(vector<int>& nums,int begin,int end){
        if(end - begin <= 1) return 0;
        int mid = (begin + end)>>1;
        int count = merge_sort(nums,begin,mid) + merge_sort(nums,mid,end);
        int right = mid;
        for(int left = begin ; left < mid ;left++){
            while(right < end && 2*(long)nums[right] < nums[left]) right++;
            count += right - mid;
        }
        inplace_merge(nums.begin() + begin,nums.begin() + mid,nums.begin() + end);
        return count;
    }
};
