/********************************************
作者:Alfeim
题目:子数组按位与操作
时间消耗:1572ms
解题思路:
直接暴力方法会超时

实际上,这题可以利用整型只有32位的性质

我们用一个set存储取得的所有可能值
然后用一个set存储上一次(新增一位)时可能出现的新值
然后用一个set存储本次出现的新值

由于整型只有32位,所以当我们遍历到一个新的数时,如果
依次向前按位与最多最多只会有32种情况(即每一次都新增
了一位1) 由此可以降低时间复杂度(如果时暴力的话遍历
数目就不是常数级了)

********************************************/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> tmp;
        unordered_set<int> last;
        unordered_set<int> res;
        
        for(auto i : A){
            tmp = {i};
            for(auto j : last) tmp.insert(j | i);
            last = tmp;
            for(auto j : tmp) res.insert(j);
        }
        
        return res.size();
    }
};
