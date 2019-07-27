/********************************************
作者:Alfeim
题目:数组中两个数的最大异或值
时间消耗:168ms
解题思路:见https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/solution/li-yong-yi-huo-yun-suan-de-xing-zhi-tan-xin-suan-f/
********************************************/
//利用a^b = c <===> a ^ c == b的性质
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int res = 0;
        for(int i = 31 ; i >= 0 ; --i){
            mask |= (1 << i);
            
            unordered_set<int> record;
            for(auto j : nums) record.insert(mask & j);
            
            int tmp = res | (1 << i);
            for(auto k : record){
                if(record.count(tmp^k) > 0){
                    res = tmp;
                    break;
                }
            }
        }
        
        return res;
        
        
    }
};
