/********************************************
作者:Alfeim
题目:最大间距
时间消耗:12ms
解题思路:题目要求时间复杂度O(n)能符合这个情况的首先想到桶排序.
我们用两个数组Max和Min分别表示对应桶中的最大值和最小值.要注意
的是，相邻元素的最大差值一定是某个非空桶中的最小值与位于其之前
的第一个非空桶中的最大值之差。 具体解释的话，可以这么理解，理
想情况下，桶排序中的所有元素呈现出均匀分布，即每一个位置上都只
有一个元素---这时候显然题意中的最大差为1； 而一旦不是均匀分布，
类似从某些桶中抽出了一些元素，放入到了其他桶。这时候，一定会有
空桶出现，而如果两个非空桶之间存在"空桶",也就意味着后一个桶中
最小的元素比前一个桶中最大的元素还要大"一个以上桶的容量",这个
差值一定大于桶内相邻元素的差值(桶内元素差值不会超过桶的容量)。
********************************************/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int res = 0;
        int Max = 0;
        int Min = INT_MAX;
        
        for(auto i : nums){
            Max = max(i,Max);
            Min = min(i,Min);
        }
        
        int diff = (Max - Min)/nums.size()  < 1 ?  1 : (Max - Min)/nums.size();   
        int count = ( Max - Min )/diff + 1,begin = count;
        vector<int> Max_Val(count,0);
        vector<int> Min_Val(count,INT_MAX);
        vector<bool> used(count,false);

        for(auto i : nums){
            int pos = (i - Min)/diff;
            used[pos] = true;
            begin = min(pos,begin);
            Max_Val[pos] = max(Max_Val[pos],i);
            Min_Val[pos] = min(Min_Val[pos],i); 
        }
        
        int cur = begin + 1,last = begin;
        for(;cur < count ; ++cur){
            if(!used[cur]) continue;    
            res = max(res,Min_Val[cur] - Max_Val[last]);
            last = cur;
        }
        
        return res;
    }
};
