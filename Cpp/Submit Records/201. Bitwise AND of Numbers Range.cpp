/********************************************
作者:Alfeim
题目:数字范围按位与
时间消耗:12ms
解题思路:我们从较大那个数(n)二进制表示的最低位开始逐渐扩展,假设其一共有k位，
而当前位之前还有p位: 如果n的高p位所表示的数比m的高p位所表示的数大，说明低
k-p位的任意一位都可以置0，且位于m与n的范围内(任意一位置零后一定小于等于n自
身，而因为n的高p位大于m的高p位，所以无论低位怎么变换，总是大于n的)
********************************************/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)
            return m;        
        int ans = n;
        int pos = 1;
        int tmp1 = m;
        int tmp2 = n;  
        while(tmp1 > 0){
            tmp1 >>= 1;
            tmp2 >>= 1;
            if(tmp2 <= tmp1)
                break;
            pos++;
        }
        ans >>= (pos);
        ans <<= (pos);
        ans &= m;
        return ans;
    }

};
