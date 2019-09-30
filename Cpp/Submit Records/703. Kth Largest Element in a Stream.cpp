/********************************************
作者:Alfeim
题目:数据流重的第K大元素
时间消耗:60ms
解题思路:最小堆/multiset
********************************************/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums):border(k),size(nums.size()){
        for(auto i : nums) container.insert(i);
    }
    
    int add(int val) {

        container.insert(val);
        size++;
        
        while( size > border ){
            auto it = container.end();it--;
            container.erase(it);
            size--;
        }
        
        return *(container.rbegin());     
    }
    
private:
    int size;
    int border;
    multiset<int,greater<int>> container;
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
