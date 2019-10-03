/********************************************
作者:Alfeim
题目:验证栈序列
时间消耗:20ms
解题思路:栈
********************************************/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int cur  = 0 ,left = 0;
        stack<int> tmp;
        
        for(auto i : pushed){
            
            while( !tmp.empty() && tmp.top() == popped[left]){
                tmp.pop();
                left++;
            }
            
            if( i  != popped[left]){
                tmp.push(i);
            }else if( i  == popped[left]){
                left++;
            }
        }
        
        
        while(!tmp.empty()){
            auto cur = tmp.top();
            if(cur != popped[left++]) return false;
            tmp.pop();
        }
        
        return true;
        
    }
};
