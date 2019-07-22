/********************************************
作者:Alfeim
题目:最长摆动序列
时间消耗:4ms/16ms
解题思路:动态规划的思路类似于最长单调增子序列；
但本题实际上可以利用贪心算法来将时间复杂度压缩到n
O(n):我们只需要维持一个栈来存储当前最长的摆动序列,
如果遇到的新元素会破坏摆动性,应当将栈顶元素弹出再压
入新元素(因为原本已经具有摆动性了,很容易看出弹出栈
顶后再压入新元素同样具有摆动性),且新元素的值一定
要比栈顶元素的峰值来得大,也保证替代后,可以作为
后续最长摆动序列的前缀;
********************************************/
//贪心
class Solution {
public:
    stack<int> res;
    int wiggleMaxLength(vector<int>& nums) {
        bool flag;
        for(auto i : nums){
            if(res.empty()){
                res.push(i);
                continue;
            }else if( res.size() == 1){
                if(i == res.top())
                    continue;
                else{
                    flag = i > res.top() ? true : false;
                    res.push(i);
                }
            }else{
              int last = res.top();
              if( (i > last && flag == true) || (i < last && flag == false)){
                  res.pop();
                  res.push(i);
              }else if(i == last)
                  continue;
              else{
                    flag = !flag;
                    res.push(i);
              }
            }
        }
        return res.size();
        
    }
    
    
    
//动态规划
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n;
        
        vector<int> dp(n,1);
        dp[1] = nums[1] == nums[0] ? 1 : 2;
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0 ; j < i ;++j){
                if(j == 0)
                    dp[i] = nums[i] == nums[0] ? 1 : 2;
                else{ 
                    int diff1 = nums[j] - nums[j-1];
                    int diff2 = nums[i] - nums[j];
                    if( (diff1 > 0 && diff2 < 0) || (diff1 < 0 && diff2 > 0) )
                        dp[i] = max(dp[i],dp[j] + 1);
                }
            }    
        }
        
        return dp[n-1];
    }
};
