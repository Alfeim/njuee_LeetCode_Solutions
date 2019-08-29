/********************************************
作者:Alfeim
题目:数组中的K-diff对
时间消耗:12ms
解题思路:利用map自动排序
********************************************/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if( k < 0) return 0;
        
        map<int,int> record;
        for(auto i : nums) record[i]++;
        int res = 0;
        
        for(auto i : record){
           int key = i.first;
           if(k == 0){
               if(record[key] > 1) res++; 
           }else{
               if(record.count(key + k)) res++;
           }
        }
        
        return res;  
    }
};
