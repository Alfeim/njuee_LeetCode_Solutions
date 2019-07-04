/********************************************
作者:Alfeim
题目:只出现一次的数字2
时间消耗:12ms
解题思路:数学
相似题目：No.136 只出现一次的数字
********************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        int three_times = 0;
        
        for(auto i : nums){
            twice |= (once & i);  //已经出现过一次的某位是1,如果当前数字对应的位置上也是1，说明该位置出现了两次
            once ^= i;            //如果只出现过一次，显然应当用异或...也就是上一题的算法
            
            //如果某位置既出现过一次，又出现了两次，等价于其出现了三次应当置零
            //可以这么理解,出现两次时,once对应的位置是0,twice是1,如果下一次又出现了,once又置为1,twice还是1
            three_times = ~(once & twice); 
                 
            //重置once和twice
            once = three_times & once;   
            twice = three_times & twice;
        }
        
        return once;
        
    }
};
