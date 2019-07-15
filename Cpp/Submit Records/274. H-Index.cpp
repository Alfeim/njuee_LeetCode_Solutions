/********************************************
作者:Alfeim
题目:H指数
时间消耗:8ms
解题思路:排序
********************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        int res;
        sort(citations.begin(),citations.end(),greater<int>());
        res = citations[0] >= 1 ? 1 : 0 ;
        for(int i = 1 ; i < citations.size();++i){
            if(citations[i] > i)
                res = min(i+1,citations[i]);
        }

        return res;
    }
};
