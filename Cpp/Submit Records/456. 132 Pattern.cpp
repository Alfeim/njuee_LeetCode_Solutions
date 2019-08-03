/********************************************
作者:Alfeim
题目:132模式
时间消耗:24ms
解题思路:栈,用一个栈维护一个递减序列表示132中的3,
然后从尾部开始遍历,如果遇到元素比栈顶小就入栈,否则
不断出栈直到栈顶元素大于当前元素或者栈为空,同时不断
更新132中的2为当前弹出的栈顶元素.如果遇到一个元素比
当前的2小,则返回真(因为当前的2一定是小于栈中的3的，
而且栈顶对应的3一定是比2后遍历到的)
********************************************/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> tmp;
        int second = INT_MIN;
        for(int i = n - 1; i >= 0 ; i--){
            if(nums[i] < second)
                return true;
            
            while(!tmp.empty() && tmp.top() < nums[i]){
                second = tmp.top();
                tmp.pop();
            }
            
            tmp.push(nums[i]);
        }
        
        return false;
    }
};
