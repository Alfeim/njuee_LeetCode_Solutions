/********************************************
作者:Alfeim
题目:存在重复元素2
时间消耗:36ms
解题思路:滑动窗口
相似题目：220. 存在重复元素3
********************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        int left = 0,right = -1;
        int n = nums.size();
        while(right < n && left < n){
            while(right - left < k){
                right++;          
                if(right >= n)
                    break; 
                if(record.count(nums[right]) > 0)
                    return true;        
                record.insert(nums[right]);
            }
            
            record.erase(nums[left]);
            left++;
        }
        return false;
    }
};
