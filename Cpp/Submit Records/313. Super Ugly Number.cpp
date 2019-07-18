/********************************************
作者:Alfeim
题目:超级丑数
时间消耗:72ms
解题思路:用一个数组来存储prime中所有基数对应的下一位置;
每次寻找下一丑数时,遍历该数组,将该基数对应的位于丑数
数组中的数和基数本身相乘得到可能的“下一丑数”,遍历一遍
后可以得到下一丑数中最小的,也就是真正要填入丑数数组中的.
得到下一丑数后,再遍历一次基数数组,让所有可能得到该结果的
基数下标+1;
********************************************/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
            vector<int> pos(primes.size(),0);
            vector<int> res(n,0);
            res[0] = 1;
            for (int i = 0; i < n - 1; i++)
            {
                int Min_Val = INT_MAX;
                
                for (int j = 0; j < pos.size(); j++)
                {
                    int tmp =  primes[j] * res[pos[j]];
                    Min_Val = min(Min_Val,tmp);
                }
                res[i + 1] = Min_Val;
                for(int k = 0 ; k < pos.size();++k){
                   if(res[pos[k]] * primes[k] == Min_Val)
                        pos[k]++;
                }
            }
            return res[n-1];
    }
};
