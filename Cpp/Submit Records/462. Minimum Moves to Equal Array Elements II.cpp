/********************************************
作者:Alfeim
题目:移动最少次数使得元素相等
时间消耗:20ms
解题思路:

其实就是寻找中位数,为什么是中位数呢？

说起来可能每那么直观,但是画图看看就非常直观了(前辈的建议确实很有道理,多画图)

不妨我们这样看,假设排序后的数组是[n1,n2,n3,...nk-1] nk [nk+1........n2k-1] nk表示中位数

如果我们不以nk位目标数，假设我们选区了n1----nk-1中的某一个(假设是nl)作为目标数,相当于说,对
比以nk为目标的情况,从nl----n2k-1区间的数都要多移动(nk - nl)次,而n1---nl-1区间则可以少移动
nk - nl次。结果显而易见,多移动的区间长度要大于少移动的区间长度,显然这是额外增加了移动次数

对于目标数在nk右边的情况同样如此.
如果画图看的话更明显,所以我们选择中位数作为目标数

********************************************/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        if(n % 2 != 0)
            return Solve(nums[n/2],nums);
        
        return min(Solve(nums[n/2],nums),Solve(nums[n/2 - 1],nums));
    }
    
    int Solve(int target,vector<int>&nums){
        int res = 0;
        for(auto i : nums){
            res += abs(target - i);
        }
        return res;
    }
};
