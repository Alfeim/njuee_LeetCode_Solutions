/********************************************
作者:Alfeim
题目:找到K个最接近的元素
时间消耗:312ms
解题思路:二分查找
********************************************/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end());
        vector<int> res;
        auto it1 = lower_bound(arr.begin(),arr.end(),x);
        int right = distance(arr.begin(),it1);
        int left = right - 1;
        int size = 0;
        int n = arr.size();
        while(size < k){
            if(left < 0){
                res.push_back(arr[right++]);
            }else if(right >= n){
                res.push_back(arr[left--]);
            }else{
                int diff1 = abs(arr[left] - x);
                int diff2 = abs(arr[right] - x);
                if(diff2 < diff1){
                    res.push_back(arr[right++]);
                }else{
                    res.push_back(arr[left--]);
                }
            }
            
            size++;
        }
        sort(res.begin(),res.end());
        return res;
    }

    
};
