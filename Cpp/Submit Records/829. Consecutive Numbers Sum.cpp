/********************************************
作者:Alfeim
题目:连续整数求和
时间消耗:4ms
解题思路:回溯、二分查找
相似题目：No.33 搜索旋转排序数组
********************************************/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int border = 1;
        int res = 1;
        while(border*(1+border) < 2*N) border++;
        
        for(int i = 2 ; i <= border ; ++i){
            if( i % 2 == 0){
               if(N % i == i/2) res++;
            }else{
                if( N % i == 0) res++;    
            }
            
        }
        
        return res;
        
    }
};
