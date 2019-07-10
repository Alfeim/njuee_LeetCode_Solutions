/********************************************
作者:Alfeim
题目:组合总和
时间消耗:8ms
解题思路:类似全排列
********************************************/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> numbers;
    int target;
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n; 
        for(int i = 0 ; i < 9; ++i)
            numbers.push_back(i + 1);     
        vector<int> tmp;
        Solve(tmp,0,k,0,0);
        return res;
    
    } 
    void Solve(vector<int> &tmp,int count,int k,int begin,int sum){
        if(sum >= target && count < k)
            return;    
        if(count == k){
            if(sum == target)
                res.push_back(tmp);  
            return;
        }
        for(int i = begin;i < numbers.size() ; ++i){
            tmp.push_back(numbers[i]); 
            Solve(tmp,count+1,k,i+1,sum + numbers[i]);
            tmp.pop_back();
        }
    } 
};
