/********************************************
作者:Alfeim
题目:赛车
时间消耗:28ms
解题思路:DP

dp[i]表示到达目的地i所需要的最小步数

那么 到达任何地点都可以分为两种情况：

1.向右行驶直接到达
2.先向右行驶,然后向左行驶到达
3.先向右,再向左,再向右行驶到达

对于每一个位置i,我们可以求出向右行驶的最大步数和向左行驶的最大步数，
假设向右行驶了rstep步,向左行驶了lstep步.那么现在可以做如下讨论：

1.rstep步后刚好达到目的结点 那么有dp[i] = min(dp[i],rpath);

2.rstep步后还未超过终点,先行驶lstep步后再向终点前进,则有dp[i] = min(dp[i],rstep+ 1 + lstep + 1 +dp[i - (rpath - lpath)]);
  //之所以+1两次,因为每一次换方向都要+1,所以对应于右左右的情况，换了两次方向
  
3.rstep步后,超过了i,那么我们只需要考虑返回走dp[rpath - i]步,故dp[i] = min(dp[i],rstep + 1 + dp[rpath - i]);


********************************************/
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(10001,10001);
        dp[0] = 0;
        for(int i = 1 ; i <= target ; ++i){
            for(int rstep = 1 ; ( 1 << rstep ) - 1 < 2 * i ; rstep++){
                int path1 = (1 << rstep)-1;
                if( path1 == i) dp[i] = min(dp[i],rstep);
                else if(path1 < i){
                    for(int lstep = 0; lstep < rstep ; lstep++){
                    
                        int path2 = (1 << lstep)-1;
                    
                        if(i < path1 - path2) continue;
                        
                        dp[i] = min(dp[i], lstep + rstep + 2 + dp[i - (path1 - path2)]);                   
                    }
                }
                else 
                    dp[i] = min(dp[i], rstep + 1 + dp[path1 - i]);
            }
        }
        
        return dp[target];
        
    }
};






