/********************************************
作者:Alfeim
题目:乘法表中第k小的数
时间消耗:20ms
解题思路:

二分搜索

先确定一个中间值
随后遍历每一行,除以该行号也就是某一行中有多少个因子不比该数大;
如果累加和大于等于k说明当前数超过边界,应当缩减边界的上界;
如果累加和小于k则应当增加边界的下界
********************************************/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1,high = m * n + 1;
        while(low < high){
            int mid = (low + high)/2;
            int count = 0;
            for(int i = 1 ; i <= m ; ++i){
                count += mid/i > n ? n : mid/i;
            }
            if(count >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

