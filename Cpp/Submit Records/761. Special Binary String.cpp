/********************************************
作者:Alfeim
题目:特殊的二进制序列
时间消耗:8ms
解题思路:递归
根据题意,只要是特殊序列一定满足头部是1且尾部是0
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(const string &a,const string &b){
            return a > b;
        }
    };
    string makeLargestSpecial(string S) {
        int n = S.size();
        if(n <= 2) return S;
        
        
        vector<string> tmp;
        string res("");
        
        for(int i = 0 , sbegin = 0 ,cnt = 0; i < n ; ++i){
            if(S[i] == '1') cnt++;
            else cnt--;
            
            if(cnt == 0){
                tmp.push_back('1' + makeLargestSpecial(S.substr(sbegin+1,i - sbegin - 1)) + '0');
                sbegin = i + 1;
            }
        }
         
        sort(tmp.begin(),tmp.end(),cmp());
        for(auto i : tmp) res += i;
        return res;
    }
};
