/********************************************
作者:Alfeim
题目:相同的树
时间消耗:32ms
解题思路:维护一个最大堆,遍历可能的组合,如果当前组合
的值小于堆顶元素,且容量到达了k就把堆顶出栈,然后填入
当前组合;
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            return a.first + a.second < b.first + b.second;
        }   
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> MaxHeap;
       vector<vector<int>> res;
       int m = nums1.size();
       int n = nums2.size();
       for(int i = 0 ; i < m; i++){
           for(int j = 0; j < n ; j++){
                if(MaxHeap.size() < k)
                     MaxHeap.push(make_pair(nums1[i],nums2[j]));
                else{
                    if(nums1[i] + nums2[j] < MaxHeap.top().first + MaxHeap.top().second){
                         MaxHeap.push(make_pair(nums1[i],nums2[j]));
                         MaxHeap.pop();
                    }
                    
                }
           }
       }
        
      while(!MaxHeap.empty()){
          res.push_back({MaxHeap.top().first,MaxHeap.top().second});
          MaxHeap.pop();
      }   
        
      return res;

    }
};
