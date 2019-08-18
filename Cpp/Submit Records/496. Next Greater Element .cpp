/********************************************
作者:Alfeim
题目:下一个更大的元素I
时间消耗:20ms
解题思路:递减栈、哈希表
通过维护递减栈,当我们遇到一个比栈顶元素大的元素时,
就循环出栈，直到栈为空或者栈顶元素比当前元素大.这些
出栈元素的右边第一个比其大的数也就是当前元素了;

同理,如要寻找右边第一个比当前元素小的元素,只需要维护
一个递增栈
********************************************/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> S;
        unordered_map<int,int> record;
        for(auto i : nums2){
            while(!S.empty() && i > S.top()){
                record[S.top()] = i;
                S.pop();
            }        
            S.push(i);
        } 
        for(auto &i : nums1){
            i = record.count(i) > 0 ? record[i] : -1;
        }
        return nums1;
    }
};
