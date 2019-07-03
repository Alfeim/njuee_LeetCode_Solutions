/********************************************
作者:Alfeim
题目:交错字符串
时间消耗:8ms
解题思路:动态规划、动态规划的空间优化方法
********************************************/

/***********原始代码*************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        if(s1.empty())
            return s2 == s3;
        
        if(s2.empty())
            return s1 == s3;
        
        
        vector<vector<vector<bool>>> dp(s1.size()+1,vector<vector<bool>>(s2.size()+1,vector<bool>(s3.size()+1,false)));
        dp[0][0][0] = true;
        
        for(int i = 1 ; i <= s3.size();++i){
            for(int j = 0 ;j <=  s1.size() && j <= i; ++j){
                int k = i - j;
                if( k > s2.size())
                    continue;
                dp[j][k][i] =  dp[j][k][i] || (j >= 1 && dp[j-1][k][i-1] && s1[j-1] == s3[i-1]) || ( k >= 1 && dp[j][k-1][i-1]  && s2[k-1] == s3[i-1]);
            }
        }
        
        return dp[s1.size()][s2.size()][s3.size()];
    
    }
    
    
};


/***************第一次优化，空间复杂度降低一维**************/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        if(s1.empty())
            return s2 == s3;
        
        if(s2.empty())
            return s1 == s3;
        
        
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
        dp[0][0] = true;
        
        for(int i = 1 ; i <= s3.size();++i){
            for(int j = s1.size(); j >= 0; --j){
                int k = i - j;
                if( k > s2.size())
                    continue; 
                dp[j][k] = (j >= 1 && dp[j-1][k] && s1[j-1] == s3[i-1]) || ( k >= 1 && dp[j][k-1] && s2[k-1] == s3[i-1]);
            }
        }   
        return dp[s1.size()][s2.size()];
    }
    
    
};



/*****************第二次优化，空间复杂度再降低一维*****************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        
        if(s1.empty())
            return s2 == s3;
        
        if(s2.empty())
            return s1 == s3;
         
        vector<bool> dp(s1.size()+1,false);
        dp[0] = true;
        
        for(int i = 1 ; i <= s3.size();++i){
            for(int j = s1.size(); j >= 0; --j){
               
                if( i-j > s2.size())
                    continue;  
                dp[j] = (j >= 1 && dp[j-1] && s1[j-1] == s3[i-1]) || ( i - j >= 1 && dp[j] && s2[i-j-1] == s3[i-1]);
            }
        }   
        
        return dp[s1.size()];
    }

};
