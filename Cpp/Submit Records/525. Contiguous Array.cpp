/********************************************
作者:Alfeim
题目:连续数组
时间消耗:268ms
解题思路:哈希表,用count记录累计和（遇到0就-1，遇到1
就+1，并记录当前count对应的位置），如果遇到哈希表
中出现了相同的count,说明上一个count的位置到当前count的
位置中0和1的数目一样多！
********************************************/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> record;
        record[0] = -1;
        int res = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0)
                count--;
            else 
                count++;
            
            if(record.count(count) > 0)
                res = max( i - record[count] , res);
            else
                record[count] = i;

        }
        
        return res;
        
    }
};
