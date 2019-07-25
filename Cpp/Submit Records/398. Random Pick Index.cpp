/********************************************
作者:Alfeim
题目:随机数索引
时间消耗:4ms
解题思路:蓄水池抽样法
********************************************/
class Solution {
public:
    Solution(vector<int>& nums){
        it = nums.begin();
        end = nums.end();
        
    }
    
    int pick(int target) {
        //real_pos表示真实下标(即排除target之外的数之后的下标)
        int real_pos = 1;
        int res;
        auto cur = it;
        //先找到第一个target的位置
        while(cur != end && *cur != target) cur++;
        res = distance(it,cur); 
        //然后从下一位置开始遍历,进行蓄水池抽样
        cur++;
        while(cur != end){
            if(*cur == target){
                real_pos++;
                int r = rand()%real_pos;
                if(r == 0) res = distance(it,cur);
            }
            cur++;
        }
        return res;
    }
    vector<int>::iterator end;
    vector<int>::iterator it;
};
