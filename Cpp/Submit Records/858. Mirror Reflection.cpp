/********************************************
作者:Alfeim
题目:镜面反射
时间消耗:12ms
解题思路:

把光线的运动分成水平和垂直两个方向

假设水平方向移动p距离的时间为1个单位(此时对应垂直方向移动了q距离)

那么要达到接收器的位置必须满足在第k个单位时垂直方向的移动总距离 kq是p的整数倍

实际上最小的kq也就是p和q的最小公倍数,等价于p*q除以二者的最大公约数;

最后我们只要根据 k的奇偶性质 以及 kq/p的奇偶性质即可判断到底入射到了哪个接收器

********************************************/


class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = p > q ? gcd(p,q) : gcd(q,p);
        
        int k = p / g;
        int k2 = q / g;
        
        if( k % 2 != 0 && k2 % 2 == 0) return 0;
        
        return k % 2 == 0 ? 2 : 1;
        
    }
    
    int gcd(int p , int q){
        if(q == 0) return p;
        return gcd(q,p%q);
    }
};
