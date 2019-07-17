/********************************************
作者:Alfeim
题目:区域和检索-数组可修改
时间消耗:52ms
解题思路:树状数组
********************************************/
class NumArray {
public:
    vector<int> tmp;
    vector<int> Tree;
    NumArray(vector<int>& nums):tmp(nums){
       for(int i = 0 ; i <= tmp.size() ; ++i)
           Tree.push_back(0);
        
       for(int j = 0 ; j < tmp.size();++j){
           add(j,nums[j]);
       }

    }
    
    void update(int i, int val) {
        int add = val - tmp[i];
        tmp[i] = val;
        for( int j = i + 1 ; j < Tree.size();j += lowbit(j) ){
            Tree[j] += add;
        }
        
    }
    
    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
    
    int getSum(int pos){
        int sum = 0;
        for(int i = pos ; i > 0 ; i -= lowbit(i)){
            sum += Tree[i];
        }
        return sum;
        
    }
    
    int lowbit(int val){
        return val&(-val);
    }
    
    void add(int pos,int val){
       for(int i = pos + 1; i < Tree.size();){
            Tree[i] += val;
            i += lowbit(i);
       } 
        
    }
    
};
