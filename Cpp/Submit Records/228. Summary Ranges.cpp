/********************************************
作者:Alfeim
题目:汇总区间
时间消耗:0ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0 ,right = 0;
        int n = nums.size();
        vector<string> res;
        while(left < n && right < n){
            while(1){
                if(right >= n-1) break;
                long diff = (long)nums[right+1] - (long)nums[right];
                if(diff != 1) break;
                right++;
            }
            
            if(right - left == 0){
                res.push_back(to_string(nums[left]));
            }else{
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }
            
            left = right + 1;
            right = left;
        }
        return res;
    }
};
