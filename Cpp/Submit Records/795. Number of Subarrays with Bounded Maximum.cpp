/********************************************
作者:Alfeim
题目:区间子数组个数
时间消耗:40ms
解题思路:
要求大于等于L小于等于R的区间个数
只要求小于等于R 和 小于L的 然后相减即可
********************************************/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return Count(A,R) - Count(A,L-1);
    }

    int Count(vector<int>&A,int border){
        int res = 0;
        int sum = 0;
        for(auto i : A){
            if(i <= border){
                sum++;
                res += sum;
            }else{
                sum = 0;
            }
        }
        
        return res;
    }
};
