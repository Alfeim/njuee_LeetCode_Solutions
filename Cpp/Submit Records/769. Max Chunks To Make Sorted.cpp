/********************************************
作者:Alfeim
题目:最多能完成排序的块
时间消耗:0ms
解题思路:
每一次都设一个边界next 
为了保证能还原为原排序,则至少要保证边界内的所有数一起分割，每次遍历到新的数时，
观察其边界是否比当前的边界大，如果是就更新边界，如果当前位置恰好等于边界，也就是分割点，让结果+1
********************************************/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int res = 0,pos = 0,next = -1,n = arr.size();   
        
        while(pos < n ){
            
            if(next < arr[pos]){
                next = arr[pos];
            }
            
            
            if(pos == next){
                res++;
            }
            
            pos++;
            
        }
        
        return res;   
        
    }
};
