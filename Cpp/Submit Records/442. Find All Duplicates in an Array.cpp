/********************************************
作者:Alfeim
题目:数组中的重复数
时间消耗:136ms
解题思路:两种方法,一种是置换法,另一种是用取反标记
********************************************/
//置换法
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == i + 1)
                continue;
            
            while(nums[i] != i + 1){
                
                if(nums[nums[i] - 1] == nums[i])
                    break;
                
                swap(nums[i],nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] != i + 1) res.push_back(nums[i]);
        }
        
        
        return res;
        
    }
};



//取反标记
class Solution {
public:
   vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> twice = {};
        nums.push_back(1);
        int temp = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            nums[i]>0 ? temp=nums[i] : temp = nums[i]*(-1);
            if(nums[temp]>0)
                nums[temp] = (-1)*nums[temp];
            else
                twice.push_back(temp);
        }
        return twice;
    }

};
