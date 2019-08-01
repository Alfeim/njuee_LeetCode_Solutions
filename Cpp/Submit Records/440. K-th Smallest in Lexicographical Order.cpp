/********************************************
作者:Alfeim
题目:字典序第k小的树
时间消耗:4ms
解题思路:
可以把该字典序列看成一颗十叉字典树，本质就是找到先序
遍历的第k个元素,我们在判断该数是否存在于某个子树中
时,只需要每次递减该子树中的元素个数即可.
********************************************/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k > 0){
            long long step = 0,first = cur,last = cur + 1;
            while(first <= n){
                step += min((long long)n + 1,last) - first ;
                first *= 10;
                last *= 10;
            }
            if(step <= k){
                ++cur;
                k -= step;
            }else{
                cur *= 10;
                --k;
            }
            
        }
        return cur;
        
    }
};
