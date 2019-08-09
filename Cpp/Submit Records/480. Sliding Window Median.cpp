/********************************************
作者:Alfeim
题目: 滑动窗口的中位数
时间消耗:120ms
解题思路:大小堆
********************************************/
class Solution {
public:
    multiset<int,less<int>> minHeap;
    multiset<int,greater<int>> maxHeap;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        res.reserve(n - k  + 1);  
        for(int i = 0 ; i < n ; ++i){
            minHeap.insert(nums[i]);
            int size1 = minHeap.size();
            int size2 = maxHeap.size();
            
            if(size1 + size2 > k){
                auto it1 = minHeap.find(nums[i-k]);
                auto it2 = maxHeap.find(nums[i-k]);
                if(it1 != minHeap.end()){
                    minHeap.erase(it1);
                    size1--;
                }else{
                    maxHeap.erase(it2);
                    size2--;
                }
            }
            
            
            if(size1 - size2 > 1){
                auto it = minHeap.begin();
                maxHeap.insert(*it);
                minHeap.erase(it);
                size1--;
                size2++;
            }
            
            if(size1 > 0 && size2 > 0 && *(minHeap.begin()) < *(maxHeap.begin())){
                auto it = minHeap.begin();
                maxHeap.insert(*it);
                minHeap.erase(it);
                size1--;
                size2++;
            }
            
            if(size1 < size2){
                auto it = maxHeap.begin();
                minHeap.insert(*it);
                maxHeap.erase(it);
                size1++;
                size2--;
            }
            
            if(size1 + size2 == k){
                auto it1 = *(minHeap.begin());
                auto it2 = *(maxHeap.begin());
                if(k % 2 == 0) 
                    res.push_back( (double)it1/2 + (double)it2/2 );
                else
                    res.push_back( (double)it1 );
            }
        }
        
        
        return res;

    }

    
};
