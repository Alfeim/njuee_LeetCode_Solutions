/********************************************
作者:Alfeim
题目:适龄的朋友
时间消耗:212ms
解题思路:二分查找
********************************************/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> first_pos;
        unordered_map<int,int> sameAge;
        sort(ages.begin(),ages.end());
        int n = ages.size(),res = 0;
        
        for(int i = 0 ; i < n ; ++i){
            
            if(sameAge[ages[i]] == 0){
                first_pos[ages[i]] = i;
            }    
            sameAge[ages[i]]++;
        }
        

        for(int i = 0 ; i < n ; ++i){   
            int lower_border = ages[i]/2 + 7;
            int low = Position(lower_border,0,first_pos[ages[i]] - 1,ages);
            
            if(ages[i] > 14) res += sameAge[ages[i]] - 1;
            
            
            if(first_pos[ages[i]] >= low && ages[low] > lower_border) res += (first_pos[ages[i]] - low);
        }
        
        return res;
    }
    
    
    int Position(int border,int low,int high,vector<int>& ages){
        if(low == high - 1 && ages[low] == ages[high])
            return low;
        
        if(low >= high) return low;
        
        int mid = (low + high)/2;
        
        if(ages[mid] <= border) return Position(border,mid+1,high,ages);
        
        return Position(border,low,mid,ages);
    }
};
