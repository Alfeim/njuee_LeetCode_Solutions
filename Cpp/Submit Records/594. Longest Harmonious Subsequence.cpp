/********************************************
作者:Alfeim
题目:最长和谐子序列
时间消耗:ms
解题思路:96ms
********************************************/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> counts;
        for(auto i : nums) counts[i]++;
        int res = 0;
        for(auto it : counts){
            if(counts.count(it.first + 1)){
                 res = max(it.second + counts[it.first+1],res);
            }
        }
        
        return res;
    }
};
