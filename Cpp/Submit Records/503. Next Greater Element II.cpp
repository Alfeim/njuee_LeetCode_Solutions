/********************************************
作者:Alfeim
题目:下一个更大元素
时间消耗:180ms
解题思路:维护一个递减栈即可
********************************************/
class Solution {
public:
    stack<pair<int,int>> S;
    vector<int> nextGreaterElements(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        vector<int> res(n,-1);
        
        //第一遍扫描
        for(int i = 0 ; i < n ; ++i ){
            while(!S.empty() && nums[i] > S.top().first){
                auto cur = S.top();
                S.pop();
                res[cur.second] = nums[i];
            }
            S.push(make_pair(nums[i],i));         
        }
        
        //第二遍扫描
        if(!S.empty()){
            for(int i = 0 ; i < n ; ++i){
                while(!S.empty() && nums[i] > S.top().first){
                    auto cur = S.top();
                    S.pop();
                    res[cur.second] = nums[i];
                }
            }
        }
        
        
        return res;  
    
    }
};
