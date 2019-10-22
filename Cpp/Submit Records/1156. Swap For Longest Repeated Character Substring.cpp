/********************************************
作者:Alfeim
题目:单字符重复字串的最大长度
时间消耗:12ms
解题思路:
记录每个位置左边连续子序列最大长度 以及 右边连续子序列最大长度 以及每个字符的统计次数

从头遍历，如果某个位置之前的连续子序列长度小于对应字母的统计次数 则可以从其他位置交换一个到位置i，使得新子序列长为left[i-1]+1

如果某个位置之后的连续子序列长度小于对应字母的统计次数，则可以从其他位置交换一个到位置到i，使得新子序列长尾right[i+1]+1

如果某个位置左右的字母都和该字母相同，那么如果该字母的统计次数大于左右连续子序列长度和，则可以从其他位置交换一个到位置i，使得新子序列长度为left[i-1] + right[i+1] + 1; 
********************************************/
class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
       
        if(n <= 1) return n;

        int res = 1;
        vector<int> left_count(n ,1);
        vector<int> right_count(n ,1);
        vector<int> word_count(26,0);
        
        word_count[text[0] - 'a']++;

        for(int i = 1 ; i < n ; ++i){
            word_count[text[i] - 'a']++;
            if(text[i] != text[i-1]) continue;
            left_count[i] = left_count[i-1] + 1;
        }

        for(int i = n - 2 ; i >= 0 ; --i){
            if(text[i] != text[i+1]) continue;
            right_count[i] = right_count[i+1] + 1;
        }


        for(int i = 0 ; i < n ; ++i){

            if(i > 0 && left_count[i-1] < word_count[text[i-1] - 'a']){
                res = max(res,left_count[i-1] + 1);
            }

            if(i < n - 1 && right_count[i+1] < word_count[text[i+1] - 'a']){
                res = max(res,right_count[i+1] + 1);
            }

            if(i > 0 && i < n - 1 && text[i-1] == text[i+1] && text[i-1] != text[i]){
                if( word_count[text[i-1]-'a'] > left_count[i-1] + right_count[i+1] ){
                    res = max(res,left_count[i-1] + right_count[i+1] + 1);
                }else{
                    res = max(res,left_count[i-1] + right_count[i+1]);
                }
            }
        }

        return res;

    }
};
