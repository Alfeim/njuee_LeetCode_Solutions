/********************************************
作者:Alfeim
题目:从英文中重建数字
时间消耗:20ms
解题思路:依次寻找"独有标识"的那些字母即可.
思路见https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/solution/cong-ying-wen-zhong-zhong-jian-shu-zi-by-leetcode/
********************************************/
class Solution {
public:
    unordered_map<char,int> record;
    string originalDigits(string s) {
        for(auto i : s)record[i]++;
        vector<int> numbers(11,0);
        numbers[0] = record['z'];
        numbers[2] = record['w'];
        numbers[4] = record['u'];
        numbers[6] = record['x'];
        numbers[8] = record['g'];
        numbers[3] = record['h'] - numbers[8];
        numbers[5] = record['f'] - numbers[4];
        numbers[7] = record['s'] - numbers[6];
        numbers[9] = record['i'] - numbers[5] - numbers[8] - numbers[6];
        numbers[1] = record['n'] -2*numbers[9] - numbers[7];
        string res;
        for(int i = 0 ; i < 10 ; ++i){
            res += string(numbers[i],i + '0');
        }
        return res;
    }
    
};
