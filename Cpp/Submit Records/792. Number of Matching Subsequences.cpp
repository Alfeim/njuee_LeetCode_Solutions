/********************************************
作者:Alfeim
题目:匹配子序列的单词数
时间消耗:296ms
解题思路:哈希表
********************************************/
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> counts(26,0);
        unordered_map<string,int> M;
        int Slen = S.size(),Wpos = 0,Spos = 0,Wlen = 0,res = 0;
        
        for(auto i : S) counts[i -'a']++;
        
        for(auto i : words) M[i]++;
        
        for(auto i : M){
            
            string cur(i.first);
            Wlen = cur.size();
            Wpos = 0;
            Spos = 0;
            for(; Wpos < Wlen && Spos < Slen;){
                 if(counts[cur[Wpos] - 'a'] == 0) break;
                 if(cur[Wpos] == S[Spos]) Wpos++;
                 Spos++;
            }
            
            if(Wpos == Wlen) res += M[cur];
        }
        
        return res;    
    }
};
