/********************************************
作者:Alfeim
题目:分割数组为连续子数组
时间消耗:12ms
解题思路:贪心算法+哈希表
********************************************/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> counts;
        unordered_map<int,int> Listcounts;
        for(auto i : nums) counts[i]++;
        for(auto i : nums){
            if(counts[i] == 0) continue;
            counts[i]--;
            if(Listcounts[i-1] > 0){
                Listcounts[i-1]--;
                Listcounts[i]++;
            }else{
                if(counts[i+1] > 0 && counts[i+2] > 0){
                    counts[i+1]--;
                    counts[i+2]--;
                    Listcounts[i+2]++;
                }else
                    return false;
            }
        }
        return true;
    }
};
