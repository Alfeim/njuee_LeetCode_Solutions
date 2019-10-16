/********************************************
作者:Alfeim
题目:字符串中的加粗单词
时间消耗:8ms
解题思路:用一个数组标记被加粗的位即可
********************************************/
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<bool> isBold(n,false);
        
        for(auto w : words){
            int len = w.size();
            string::size_type pos = 0;
            while(pos < n){
                string::size_type tmp = S.find(w,pos);
                if(tmp == S.npos) break;
                Solve(isBold,tmp,len,w,S);
                pos = tmp + 1;
            }
        }
        
        string res;
        
        for(int i = 0 ; i < n ;){
            if(!isBold[i]) 
                res.push_back(S[i++]);
            else{
                res.append("<b>");
                while(i < n && isBold[i]) res.push_back(S[i++]);
                res.append("</b>");
            }
        }
        
        return res;
        
    }
    
    void Solve(vector<bool> &isBold,int pos,int len,string &target,string &S){
        
        for(int i = pos,j = 0 ; i < pos + len ; ++i,++j){
            if(S[i] != target[j]) return;
        }
        
        for(int i = pos ; i < pos + len ; ++i){
            if(isBold[i]) continue;
            isBold[i] = true;
        } 
        
    }
    
 
};
