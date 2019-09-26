/********************************************
作者:Alfeim
题目:阶乘后K个0
时间消耗:4ms
解题思路:

实际上这题的核心就是围绕 X的阶乘末尾有多少0

而这个核心问题实际也就等价于 从0----X内有多少个5的因子罢了(如果单纯求有多少0反而是easy问题)

那么知道如何求末尾的0个数后 如何知道K个0的数有多少个呢？

我们发现,因为数字每多5 就多了至少一个5的因子，所以阶乘末尾是0的数 要么没有(0个) 要么就是5个

那么就可以使用二分法来逼近 初始上界为K*5(因为K*5至少有K个5的因子)
********************************************/


class Solution {
public:
    int preimageSizeFZF(int K) {
        long low = 0,high = (long)K*5;
        return Solve(0,high,K);
        
    }
    
    int Solve(long low,long high,long counts){
        if(low >= high){
            return (SumZero(low) == counts) ? 5 : 0;    
        }    
        
        long mid = (low + high)/2;
        long tmpcounts = SumZero(mid);
        
        if(tmpcounts < counts) return Solve(mid + 1, high, counts);
        else if(tmpcounts > counts) return Solve(low, mid - 1, counts);
        
        return 5;
        
    }
    
    long SumZero(long number){
        int count = 0;
        
        while(number >= 5){
            number /= 5;
            count += number;
        }
        
        return count;
        
    }
    
    
};
