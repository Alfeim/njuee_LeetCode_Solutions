/********************************************
作者:Alfeim
题目:丑数3
时间消耗:0ms
解题思路:二分查找
********************************************/
class Solution {
public:
    using LL = long long;

    int nthUglyNumber(int n, int a, int b, int c) {
        //看到n的范围应该马上联想到是，典型的二分思路
        LL low = min(min(a,b),c);                            //下边界显然是a、b、c中最小者
        LL high = static_cast<LL>(low) * n;                 //上边界是这个最小者的n倍
        
        LL res = Binary_Search(low,high,a,b,c,n);

        LL left_a = res%a;
        LL left_b = res%b;
        LL left_c = res%c;

        return res - min(left_a,min(left_b,left_c));
    }
    
    //二分搜索
    LL Binary_Search(LL low,LL high,int a,int b,int c,LL n){
        if(low >= high) return low;

        LL mid = (low + high)>>1;

        LL MCM_a_b = MCM(a,b);
        LL MCM_a_c = MCM(a,c);
        LL MCM_b_c = MCM(b,c);
        LL MCM_a_b_c = MCM(MCM_a_b,c);

        //独立的丑数个数为，当前数分别除以a、b、c的和，减去当前数除以a、b、c两两间最小公倍数的和，再加上当前数除以 a、b、c三者的最小公倍数
        LL count_n = mid/a + mid/b + mid/c - mid/MCM_a_b - mid/MCM_b_c - mid/MCM_a_c +  mid/MCM_a_b_c;
        
        if(count_n == n) return mid;
        
        if(count_n < n) return Binary_Search(mid + 1,high,a,b,c,n);

        return Binary_Search(low,mid-1,a,b,c,n);
    }

    //求最小公倍数：两数乘积除以最大公约数
    LL MCM(LL a,LL b){
        
        LL Multi = a * b;
        
        while(b > 0){
            LL tmp = a % b;
            a = b;
            b = tmp;
        }

        return Multi/a;
    }


};
