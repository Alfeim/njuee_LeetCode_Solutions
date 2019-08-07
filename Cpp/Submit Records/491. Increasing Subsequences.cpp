/********************************************
作者:Alfeim
题目:递增子序列
时间消耗:320ms
解题思路:dfs
********************************************/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        dfs(nums,0,n,tmp);
        return res;
    }
    
    void dfs(vector<int> nums,int pos,int len,vector<int> &tmp){
        if(pos >= len)
            return;
        
        unordered_set<int> record;
        
        for(int i = pos; i < len ; ++i){
            if(record.count(nums[i]) > 0)
                continue;
            
            if(tmp.empty() || nums[i] >= tmp.back()){
                record.insert(nums[i]);
                tmp.push_back(nums[i]);
                if(tmp.size() >= 2) res.push_back(tmp);
                dfs(nums,i + 1, len , tmp);
                tmp.pop_back();
            }
        }
        
        return;
        
    }
};
