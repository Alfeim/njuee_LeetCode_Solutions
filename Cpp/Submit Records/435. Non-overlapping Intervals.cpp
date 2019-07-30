/********************************************
作者:Alfeim
题目:无重叠区间
时间消耗:4ms
解题思路:贪心算法

先对所有元素按照区间起始进行排序

然后开始遍历数组,如果遇到栈为空就直接入栈

如果当前元素的区间起始 大于或者等于 栈顶元素区间终点 就将当前元素入栈

如果当前元素的区间终点比栈顶元素的区间终点小,就把栈顶元素移出并填入当前元素
********************************************/
class Solution {
public:
    stack<pair<int,int>> S;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &v1,vector<int> &v2){return v1[0] < v2[0];});
        
        for(auto i : intervals){
            if(S.empty())
                S.push(make_pair(i[0],i[1]));
            else{
                auto tmp = S.top();
                
                if(i[0] >= tmp.second)
                    S.push(make_pair(i[0],i[1]));
                else if(i[1] < tmp.second){
                    S.pop();
                    S.push(make_pair(i[0],i[1]));
                }              
            }
        return n - S.size();

    }
};
