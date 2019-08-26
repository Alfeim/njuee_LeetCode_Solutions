/********************************************
作者:Alfeim
题目:分割数组为连续子数组
时间消耗:12ms
解题思路:贪心算法+哈希表
用一个哈希表记录各个数字的剩余次数
另一个哈希表记录以某个数字为结尾的字符串个数

遍历每一个数字,如果当前数字的次数已经用完就跳过
否则,先查看是否有以该数字-1为结尾的数组,如果有,就让该数字-1
结尾的数组记录-1,并让该数字结尾的数组记录+1

如果没有,就看是否存在该数字+1和+2的数,如果有,将对应的数
的记录各-1,并让以该数字+2为结尾的数组记录+1;

如果还是没有就返回false;
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
