/********************************************
作者:Alfeim
题目:森林中的兔子
时间消耗:12ms
解题思路:哈希表
********************************************/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> rabbits;
        int res = 0;
        for(auto i : answers){
            if(rabbits[i] > 0) 
                rabbits[i]--;
            else{
                rabbits[i] = i;
                res += i + 1;
            }
        }
        return res;   
    }
};
