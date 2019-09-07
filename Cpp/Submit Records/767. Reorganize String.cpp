/********************************************
作者:Alfeim
题目:重构字符串
时间消耗:0ms
解题思路:每次填入都选则剩余字母中，剩余次数最多且与上一次填入的字母不同的来填入
********************************************/
class Solution {
public:
    string reorganizeString(string S) {
        string res;
        vector<int> counts(26,0);
        int n = S.size();
        int Max = 0;
        
        for(auto i : S){
            counts[i-'a']++;
            Max = max(Max,counts[i-'a']);
        }
        
        if( Max > (n+1)/2) return "";
        
        char last = '*';
        char cur;
        for(int i = 0 ; i < n ; ++i){
            int tmpMax = 0;
            for(char c = 'a' ; c <= 'z'; ++c){
                if(counts[c - 'a'] > 0 && counts[c - 'a'] > tmpMax && c != last){
                    cur = c;
                    tmpMax = counts[c - 'a'];
                }
            }
            
            counts[cur - 'a']--;
            last = cur;
            res += cur;
        }
        return res;
        
    }
};
