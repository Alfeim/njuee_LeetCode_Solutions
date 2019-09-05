/********************************************
作者:Alfeim
题目:三个无重叠子数组的最大和
时间消耗:超时(待优化)
解题思路:DP
********************************************/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1,0);sum[0] = 0;
            //sum[i]存储nums到下标i为止的和,方便后续计算
        for(int i = 1 ; i <= n ; ++i) sum[i] = sum[i-1] + nums[i-1];
        //dp存储到长度i为止,j个长度为k的数组的最大和；
        vector<int> dp(n + 1,0);
        //pos存储到长度i为止,j个长度为k的数组和最大情况下,最后一个数组的起始索引号；初始化dp[k][0]\dp[2k][1]\dp[3k][2]
        vector<vector<int>> pos(n + 1,vector<int>(4,0));pos[k][1] = 0 ; pos[2*k][2] = k; pos[3*k][3] = 2*k;    
        //直接从下标k开始遍历(k之前的情况已经不用考虑了,因为除了初始化dp[k][0]有意义外,其他均没有意义)
        int tmp = 0;
        for(int j = 1 ; j <= 3 ; ++j){
            //遍历j(即有多少个独立子数组)
            for(int i = n ; i >= k  ; --i){
                //对于每一种j,长度至少要满足刚好
                if(i >= k*j && n - i >=  k*(3-j)){                    
                    //遍历最后一个数组可能的所有位置,从末尾下标开始遍历,直到至少满足刚好填入j+1个长度为k的数组
                    for(int l = i ; l >= k*j ; --l){
                        if(i == j*k){
                            dp[i] = sum[j*k];
                            break;
                        } 
                        //用最后一个数组的和加上先前j个数组的最大和,表示可能的情况
                        tmp = sum[l] - sum[l - k ] + dp[l-k];
                        //如果比先前的情况大,就更新dp和pos
                        if(tmp >= dp[i]){
                            dp[i] = tmp;
                            pos[i][j] = l - k;
                        }
                    }
                }
            }
        }
        
        vector<int> res(3,0);    
        res[2] = pos[n][3];
        res[1] = pos[res[2]][2];
        res[0] = pos[res[1]][1];
        return res;
    }
};
