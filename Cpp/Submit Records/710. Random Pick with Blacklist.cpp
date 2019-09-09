/********************************************
作者:Alfeim
题目:黑名单中的随机数
时间消耗:520ms
解题思路:
由于黑名单的长度远远小于白名单,因此一种思路是
保留我们的状态空间为[0,N - Blen],也就是说保留
小于N-Blen中的所有数,那么那些大于这个阈值且不在黑名单
中的数怎么办呢？

我们可以让小于该阈值中的所有位于黑名单中的数 与
大于该阈值中的 所有位于白名单的数进行一一映射(
显然两者数目相等)！
********************************************/
class Solution {
public:
    Solution(int N, vector<int>& blacklist){
        int Blen = blacklist.size();
        Wlen = N - Blen; 
        unordered_set<int> S;
        for(int i = Wlen ; i < N ; ++i) S.insert(i);
        for(auto b : blacklist) S.erase(b);
        auto it = S.begin();
        for(auto i : blacklist){
            if(i < Wlen) records[i] = *it++;
        }
        
    }
    
    int pick() {
        int tmp = rand()%Wlen;
        return records.count(tmp) ? records[tmp] : tmp; 
           
    }
    
    int Wlen;
    unordered_map<int,int> records;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

