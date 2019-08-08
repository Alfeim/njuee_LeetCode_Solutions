/********************************************
作者:Alfeim
题目:最大回文数乘积
时间消耗:356ms
解题思路:

除了1位数得最大回文乘积(9)之外
其他n位数得最大回文乘积一定是2n位的
所以只需要先确定n位数的上下界,其回文乘积一定是
其中某个数与其翻转拼接得到的回文数之一。

得到某个可能的回文数后,只需从上界开始遍历(直到
该回文数的开平方),看看能否被该除数整除即可

********************************************/
class Solution {
public:
    int largestPalindrome(int n) {
        int upper_bound = pow(10,n) - 1;
        int lower_bound = pow(10,n-1);
        for(int i = upper_bound ; i >= lower_bound ; --i){
            string tmp = to_string(i);
            long target_number = stol(tmp + string(tmp.rbegin(),tmp.rend()));
            for(long j = upper_bound ; j * j >= target_number ; --j){
                if(target_number % j == 0)
                    return target_number % 1337;
            }
        }
        return 9;
    }
};
