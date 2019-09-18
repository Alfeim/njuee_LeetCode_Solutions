/********************************************
作者:Alfeim
题目:破解保险箱
时间消耗:84ms
解题思路:dfs、哈希表

用哈希表记录已经出现过的密码,
同时从n位0开始,每次新密码 = 最后n位 + （0-k）中的数字;
如果该密码没有出现过,就让当前字符串+1位(即为对应数字)
********************************************/

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> records;
        int border = pow(k,n);
        string res(n,'0');
        records.insert(res);
        
        for(int i = 1 ; i <= border ; ++i){
            int len = res.size();
            string tmp(res.substr(len - n + 1,n-1));
            for(int j = k - 1; j >= 0 ; --j){
                string key(tmp + to_string(j));
                if(!records.count(key)){
                    res += to_string(j);
                    records.insert(key);
                    break;
                }
            }   
        }
        
        return res;   
    }
};
