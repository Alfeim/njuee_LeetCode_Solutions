/********************************************
作者:Alfeim
题目:两个数组的交集
时间消耗:4ms
解题思路:运用STL容器
********************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> Set;
        unordered_set<int> record;
        vector<int> res;
        for(auto i : nums1)
            record.insert(i);

        for(auto i : nums2){
            if(Set.count(i) == 0 && record.count(i) > 0){
                res.push_back(i);
                Set.insert(i);
            }
        }
        return res;        
    }
};
