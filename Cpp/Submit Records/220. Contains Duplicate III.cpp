/********************************************
作者:Alfeim
题目:存在重复元素3
时间消耗:32ms
解题思路:1、利用set自动排序 + 滑动窗口
2、利用桶排序可以方便比较相邻元素差值 + 滑动窗口
3、利用二叉搜索树
相似题目: 219.存在重复元素2
********************************************/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <= 0)
            return false;  
        int left = 0, right = -1;
        int n = nums.size();
        multiset<int> S;
        while(left < n && right < n){
            while(right - left < k){
                right++;
                
                if(right >= n)
                    break;   
                if(S.count(nums[right]) > 0)
                    return true;  
                S.insert(nums[right]);
                auto it = S.find(nums[right]);
                auto next = it,before = it;
                before--;
                next++;
                if(it != S.begin()){
                    if(abs((long)(*before) - (long)(*it)) <= t )
                        return true;
                }
                if(next != S.end()){
                     if(abs((long)(*next) - (long)(*it)) <= t )
                        return true;
                }
            
            }   
            S.erase(S.find(nums[left]));
            left++;         
        }  
        return false;

    }
};
