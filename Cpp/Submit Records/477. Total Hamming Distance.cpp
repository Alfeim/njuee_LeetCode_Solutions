/********************************************
作者:Alfeim
题目:汉明距离总和
时间消耗:80ms
解题思路:

用一个容量为32的数组记录到目前为止，各个位上出现的"1"的次数

那么,显然,目前为止各位上出现0的次数,也就是目前为止遍历的长度减去对应的1的次数即可

当我们遍历一个新的数时,遍历该数的每一位,如果该位是1,结果就加上对应位置上已经出现的
0的次数，同时更新该位置1的出现次数；如果该位是0，就直接加上对应位置出现过的1的次数
即可

********************************************/
class Solution {
public:
    int res;
    int totalHammingDistance(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n = nums.size();
        vector<int> record_1_(32,0);   //记录到目前为止,每个位置上出现1的次数
        res = 0;
        int first = nums[0];
        for(int i = 0 ; i < 32 && first > 0;++i){
            record_1_[i] = (first & 1 == 1) ? 1 : 0;
            first >>= 1;
        }
        for(int i = 1 ; i < n ; ++i){
            Solve(nums[i],record_1_,i);
        }
        return res;
    }
    
    void Solve(int number,vector<int> &record_1_,int n){
        for(int i = 0; i < 32 ; ++i){
            if(number & 1 == 1){
                res += n - record_1_[i];
                record_1_[i]++;
            }else{
                res += record_1_[i]; 
            }
            number >>= 1;
        }
    }
    
};
