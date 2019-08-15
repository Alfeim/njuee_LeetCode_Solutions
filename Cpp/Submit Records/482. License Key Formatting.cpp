/********************************************
作者:Alfeim
题目:密钥格式化
时间消耗:12ms
解题思路:没啥好说..
********************************************/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string valid;
        for(auto i : S){
            if(i != '-') {
                if(isdigit(i)) valid += i;
                else valid += (i & '_');
            }
        }
        
        if(valid.empty())
            return "";
        
        int len = valid.size();

        int first_len = len % K == 0 ? K : len % K;
        
        string res;
        for(int i = 0 ; i < first_len ; ++i) res += valid[i] ;
        for(int i = first_len ; i < len ;i += K) res += "-" + valid.substr(i,K);
        return res;
    }
};
