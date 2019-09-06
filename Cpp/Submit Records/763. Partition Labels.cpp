/********************************************
作者:Alfeim
题目:划分字母区间
时间消耗:12ms
解题思路:
先遍历一次所有字符,记录每个字符最后出现的位置

然后每次划分新片段时,找到当前位置字母的最后位置,每次选取其和next
中最大的作为next(表示结束位置).如果当前位置恰好等于next,则划分完
了一个片段
********************************************/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26,0);
        vector<int> res;
        int n = S.size();
        for(int i = 0 ; i < n ; ++i) last[S[i]-'a'] = i;    
        int pos = 0,next = -1,last_pos = 0;
        while(pos < n){
            if(next < pos){
                next = last[S[pos] - 'a'];
                last_pos = pos;
            }
            
            if(pos == next){
                res.push_back(pos - last_pos + 1);
            }
            
            next = max(next,last[S[pos] - 'a']);
            pos++;
        }
        
        return res;
    }
};
