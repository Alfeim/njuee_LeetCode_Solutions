/********************************************
作者:Alfeim
题目:H指数2
时间消耗:28ms
解题思路:二分查找
相似题目：274. H指数
********************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
       if(citations.empty())
            return 0;
       int size = citations.size();
       int pos = Solve(citations,0,size-1);
       return citations[pos] >= size - pos ? size - pos : 0;
    }
    
    int Solve(vector<int>& citations,int low,int high){
        if(low == high)
            return low;
        
        int mid = (low + high)/2;
        int size = citations.size();
        if(citations[mid] == size - mid){
            return mid;
        }else if(citations[mid] > size - mid){
            return Solve(citations,low,mid);
        }
        return Solve(citations,mid + 1,high);
    }

};
