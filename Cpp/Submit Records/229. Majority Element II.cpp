/********************************************
作者:Alfeim
题目:求众数2
时间消耗:4ms
解题思路:在摩尔投票算法的基础上改变;可以证明,如果有超过n/3个数的元素
存在,其最多只有两个,所以需要两组变量来进行摩尔投票算法
算法可见:https://blog.csdn.net/qq_38735931/article/details/82386177
相似题目:169. 求众数
********************************************/
class Solution {
public:
    vector<int> res;
    vector<int> majorityElement(vector<int>& nums) {
        int candidates1 = 0;
        int candidates2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for(auto i : nums){
            if( candidates1 == i){
                count1++;
            }else if(candidates2 == i){
                count2++;
            }else if(count1 == 0){
                count1 = 1;
                candidates1 = i;
            }else if(count2 == 0){
                count2 = 1;
                candidates2 = i;
            }else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0; 
        for(auto i : nums){
            if( i == candidates1)
                count1++;
            else if(i == candidates2)
                count2++;
        }  
        if(count1 > n/3)
            res.push_back(candidates1);
        if(count2 > n/3)
            res.push_back(candidates2);
        return res;

    }
};
