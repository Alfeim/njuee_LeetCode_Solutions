/********************************************
作者:Alfeim
题目:分发饼干
时间消耗:60ms
解题思路:排序、双指针
********************************************/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size();
        int n = s.size();
        int child = 0 ;
        for(int i = 0 ; i < n && child < m;i++){
            if(s[i] >= g[child])
                child++;
        }
        return child;
    }
};
