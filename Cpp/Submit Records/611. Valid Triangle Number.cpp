/********************************************
作者:Alfeim
题目:有效三角形个数
时间消耗:202ms
解题思路:二分搜索、排序
********************************************/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n < 3) return 0;
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0) continue;
            for(int j = i + 1 ; j < n ; ++j){
                if(nums[j] == 0 ) continue;
                auto pos = lower_bound(nums.begin(),nums.end(),nums[i] + nums[j]);
                int distance = 0;
                if(pos != nums.end())
                    distance = pos - nums.begin() - 1;
                else
                    distance = n - 1;
                res += distance - j;
            }
        }
        
        return res;
        
    }
};
