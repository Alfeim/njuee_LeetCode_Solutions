/********************************************
作者:Alfeim
题目:可怜的小猪
时间消耗:4ms
解题思路:数学
********************************************/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)
            return 0;
        
        //一只小猪所能分辨的最大桶数,相当于一只猪猪可以携带的信息位数
        int InfoBits = minutesToTest/minutesToDie + 1;
        //接下来,循环判断需要多少只猪猪才能表示这么多的桶所代表的信息,每多一只猪,相当于携带信息可以乘上一只猪所能表示的信息
        //比如一个二进制数能表示2位信息,两个二进制数就能表示4位信息,以此类推
        int res = 1;
        int multi = InfoBits;
        while(multi < buckets){
            res++;
            multi *= InfoBits;
        }
        return res;
    }
};
