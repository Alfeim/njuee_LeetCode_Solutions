/********************************************
作者:Alfeim
题目:构建回文串检测
时间消耗:432ms
解题思路:
用一个二维数组记录各个字母的前缀和，表示到下标i位置某个字母出现了多少次
由于同一个字母可以两两匹配，所以每一个区间段多余的某个字母数，实际是该区间段的该字母数对2取余
那么，所需得最少变换次数也就是这些多余得字母数之和除以2
********************************************/
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> res;
        vector<vector<int>> prefix(26,vector<int>(n + 1,0));
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < 26 ; ++j){
                prefix[j][i+1] = prefix[j][i] + ( s[i] - 'a' == j ? 1 : 0);
            }
        }  

        for(auto i : queries){
            res.push_back(valid(prefix,i[0],i[1],i[2]));
        }

        return res;
    }

    bool valid(vector<vector<int>> &prefix,int left,int right,int k){
        int sum = 0;

        for(int i = 0 ; i < 26 ; ++i){
            sum += (prefix[i][right+1] - prefix[i][left])%2;
        }

        return (sum/2) <= k; 
    }
};
