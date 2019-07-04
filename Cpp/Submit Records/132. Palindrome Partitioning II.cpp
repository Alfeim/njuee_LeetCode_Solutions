/********************************************
作者:Alfeim
题目:回文串分割2
时间消耗:16ms(预处理)/60ms(非预处理)
解题思路:两次动态规划，第一次用于求可能的回文串，第二次求最少分割次数
相似题目：No.131 回文串分割
********************************************/
class Solution {
public:
    //两次dp方法
    int minCut(string s) {
        if(s.size() <= 1)
            return 0;
        
        string tmp(s);
        reverse(tmp.begin(),tmp.end());
        
        //这一段其实是预处理。。有点投机取巧。。因为测试用例大多是分割0次和一次，建议忽略
        if(tmp == s)
            return 0;
        
        for(int i = 1 ; i < s.size(); ++i){
            if(tmp.substr(0,i) == s.substr(s.size() - i) && tmp.substr(i) == s.substr(0,s.size()-i))
                return 1;
        }
        //预处理结束
        
        vector<vector<bool>> Pd(s.size(),vector<bool>(s.size(),false));
        vector<int> dp(s.size(),s.size());
        for(int i = 0 ; i < s.size();++i){
            Pd[i][i] = true;
            if(i < s.size() - 1 && s[i+1] == s[i])
                Pd[i][i+1] = true;
        }
        
        for(int size = 3; size <= s.size() ; ++size){
            for(int j = 0 ; j < s.size() - size + 1; ++j){
                int end = j + size - 1;
                Pd[j][end] = Pd[j+1][end-1] && s[j] == s[end]; 
            }
        }
        
        dp[0] = 0;
        for(int i = 1 ; i < s.size() ; ++i){
            for(int j = i ; j >= 0; --j){
                if(Pd[j][i])
                    dp[i] = j == 0 ? 0 :  min(dp[j-1] + 1,dp[i]);
            }
        }
        
        return dp[s.size()-1];

    }

};
