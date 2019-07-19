/********************************************
作者:Alfeim
题目:整数拆分
时间消耗:4ms
解题思路:尽量拆成多个3和2的组合
********************************************/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> res(58,0);
        res[2] = 1;
        res[3] = 2;
        res[4] = 4;
        for(int i = 5 ; i <= n ; ++i){
                if( i % 3 == 2)
                    res[i] = pow(3,i/3) * 2;         
                else if(i%3 == 1)
                    res[i] = pow(3,i/3-1) * 4;
                else
                    res[i] = pow(3,i/3);     
        }  
        return res[n];
    }
};
