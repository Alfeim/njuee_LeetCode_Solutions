/********************************************
作者:Alfeim
题目:寻找比目标字母大的最小字母
时间消耗:8ms
解题思路:二分查找
********************************************/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int res = Solve(letters,0,n-1,target);
        return res == -1 ? letters[0] : letters[res];
        
    }
    
    int Solve(vector<char>& letters,int low,int high,char &target){
        if(low >= high){
            return letters[low] > target ? low : -1;
        }
        
        int mid = (low + high)>>1;
        
        if(letters[mid] <= target) return Solve(letters,mid+1,high,target);
        
        return Solve(letters,low,mid,target);
    }
};
