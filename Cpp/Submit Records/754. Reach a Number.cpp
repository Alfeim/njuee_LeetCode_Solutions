/********************************************
作者:Alfeim
题目:到达终点的数字
时间消耗:0ms
解题思路:

因为累计步长是递增的 也就是1 、 2 .....n

我们先计算第一个累计和大于等于target的情况

如果恰好等于target ，那么step也就是当前的step

如果大于target 先计算当前和与target的差，如果是偶数，前面必然有个数可以取反使得累计和恰好等于target(取反相当于累计和减去2*该数)

如果当前差为奇数 就递增step 直到 差值为偶数为止

********************************************/
class Solution {
public:
    int reachNumber(int target) {
        
        if(target == 0) return 0; 
        target = abs(target);
        int basic = sqrt(2*target);
        if(distance(basic) < target) basic += 1;
        int dist1 = distance(basic);
        if( (dist1 - target)%2 == 0 ) return basic;
        int dist2 = distance(basic+1);
        if( (dist2 - target)%2 == 0 ) return basic + 1;
        return basic + 2;

    }

    int distance(int step){
        return ( step * (step + 1) ) >> 1;
    }
    
};
