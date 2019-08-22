/********************************************
作者:Alfeim
题目:相对名次
时间消耗:20ms
解题思路:排序
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int> &p1,const pair<int,int> &p2) const{
            return p1.first > p2.first;
        }
    };
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> tmp;
        int n = nums.size();
        vector<string> res(n);
        for(int i = 0 ; i < n ; ++i) tmp.push_back(make_pair(nums[i],i));
        sort(tmp.begin(),tmp.end(),cmp());
        for(int i = 0 ; i < n ; ++i){
            if(i == 0) res[tmp[i].second] = "Gold Medal";
            else if(i == 1) res[tmp[i].second] = "Silver Medal";
            else if(i == 2) res[tmp[i].second] = "Bronze Medal";
            else res[tmp[i].second] = to_string(i+1);
        }
        
        return res;


    }
};
