/********************************************
作者:Alfeim
题目:最小移动次数使得数组元素相等
时间消耗:88ms
解题思路:
数学:把除了一个元素之外的所有元素+1等价于将该元素-1
所以只需要计算每一个元素减到最小元素的次数和即可

也可以使用DP
********************************************/

class Solution {
public:
     //数学 
     int minMoves(vector<int>& nums) {
        int res = 0;
        if(nums.empty())
            return res;
         
        int minval = INT_MAX;
        for(auto i : nums)
            minval = min(minval,i);
      
        for(auto i : nums)
            res += i - minval;

        return res;
         
     }
    
    //动态规划
    int minMoves(vector<int>& nums) {
        if(nums.empty())
            return 0;   
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp1(n,0);   //dp1[i]表示到下标i为止的数组,对齐后的最终数字是多少
        vector<int> dp2(n,0);   //dp2[i]表示到下标i为止的数组,对齐需要移动多少次
        dp1[0] = nums[0];
        dp2[0] = 0;
        for(int i = 1 ; i < n ; ++i){
            //转移方程,可以这么理解:当我们遍历到下标为i的元素时,先让i-1以前的数组对齐,但是现在需要一次性移动i-1个元素,
            //而让i-1以前的数组对齐需要移动i-2个元素,所以我们把这多出来的元素放到最后一个元素(也就是当前元素)身上,所以
            //当前元素在对齐后应当加上对齐i-1个元素的步数,也就是dp1[i] = nums[i] + dp2[i-1]
            dp1[i] = nums[i] + dp2[i-1];   
            
            
            //在我们确定了对齐后的数字dp1[i]后,就可以计算对齐需要的步数了,其相当于对齐i-1个元素的步数(dp2[i-1])加上当前对齐后的
            //数值比上一状态对齐后的数值多出来的部分(dp1[i] - dp1[i-1])
            dp2[i] = dp1[i] - dp1[i-1] + dp2[i-1] ;
        }
        
        return dp2[n-1];
        
    }
};
