/********************************************
作者:Alfeim
题目:在D天内送达包裹的能力
时间消耗:52ms
解题思路:二分法
********************************************/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0,high = 0,n = weights.size();
        int res = INT_MAX;
        
        for(auto i : weights){
            low = max(low,i);
            high += i;
        }

        //最大值即所有货物的重量
        //最低值应该是平均值(向上取整) 和 最大重量 中 较大者
        low = max(low,(high-1 + n)/n);
        
        while(low < high){
            int mid = (low + high)>>1;
            if(enough(weights,D,mid)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    
    bool enough(vector<int>& weights,int D,int ability){
        int tmp = ability;
        
        for(auto i : weights){
            
            if(tmp < i){
                tmp = ability;
                D--;
            }         
            tmp -= i;  
        } 
        return D > 0;
        
    }
    
};
