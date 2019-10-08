/********************************************
作者:Alfeim
题目:1比特与2比特字符
时间消耗:4ms
解题思路:从头开始遍历 遇到1就跳一位 如果能遍历到最后一位说明有效
********************************************/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) { 
        int n = bits.size();
        for(int i = 0 ; i < n ; ++i){
            if(i == n - 1) return true;
            if(bits[i] == 1) i++;
        }
        
        return false;
    }
};
