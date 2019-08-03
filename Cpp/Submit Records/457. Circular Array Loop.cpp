/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:4ms
解题思路:dfs
********************************************/
class Solution {
public:
    int begin;
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n,0);
        for(int i = 0 ; i < n ; ++i){
            if(visited[i] == -1) continue;
            bool flag = nums[i] > 0 ? true : false;
            if(Solve(nums,n,i,visited,flag)) return true;
        }
        return false;
    }
    
    bool Solve(vector<int>& nums,int size,int pos,vector<int> &visited,bool flag){
        if(visited[pos] == -1)
            return false;
        
        if(visited[pos] == 1) 
            return true;
        
        visited[pos] = 1;
        
        int next_pos = (pos + nums[pos]) % size;
        if(next_pos < 0 ) next_pos += size;
        bool tmpflag = nums[next_pos] > 0 ? true : false;
        
        if(pos == next_pos || tmpflag != flag || !Solve(nums,size,next_pos,visited,flag)){
            visited[pos] = -1;
            return false;
        }
        
        return false;
        
    }
};
