/********************************************
作者:Alfeim
题目:子集2
时间消耗:4ms
解题思路:回溯
相似题目：No.78 子集
********************************************/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i <= nums.size() ; ++i){
            Solve(nums,tmp,i,0);
        }
        return res;
    }  
    void Solve(vector<int>& nums,vector<int>& tmp,int size,int begin){
        if(tmp.size() == size){
            res.push_back(tmp);
            return;
        } 
        unordered_set<int> record; 
        for(int i = begin ; i <= nums.size() - (size - tmp.size()) ; ++i){
            if(record.count(nums[i]))
                continue;
            record.insert(nums[i]);
            tmp.push_back(nums[i]);
            Solve(nums,tmp,size,i+1);
            tmp.pop_back();
        }      
    }
};
