/********************************************
作者:Alfeim
题目:搜索二维矩阵
时间消耗:12ms
解题思路:递归定位所在行,再利用二分查找搜索目标数
********************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {  
        return Solve(matrix,0,target);
    }
    
    bool Solve(vector<vector<int>>& matrix,int row,int target){
        if(row >= matrix.size() || matrix[row].empty())
            return false;
        
        if(target > matrix[row][matrix[0].size()-1])
            return Solve(matrix,row + 1,target);
        
        return Search(matrix[row],0,matrix[row].size()-1,target);
    }
    
    bool Search(vector<int> Row,int begin,int end,int target){
        int mid = (begin + end)/2;
        
        if(begin > end)
            return false;
        
        if(Row[mid] == target)
            return true;
        
        return target > Row[mid] ? Search(Row,mid+1,end,target) : Search(Row,begin,mid-1,target);
        
    }

};
