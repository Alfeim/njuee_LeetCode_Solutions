/********************************************
作者:Alfeim
题目:字符串相加
时间消耗:4ms
解题思路:字符串操作
********************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        stack<char> tmp;
        string res("");
  
        while(i >= 0 || j >= 0){
            int nums1 = i >= 0 ? num1[i--]  - '0': 0;
            int nums2 = j >= 0 ? num2[j--]  - '0': 0;
            int sum = nums1 + nums2 + carry;
            char c = sum%10 + '0';
            carry = sum/10;
            tmp.push(c);
        }
        
        if(carry > 0)
            tmp.push('1');
        
        while(!tmp.empty()){
            res += tmp.top();
            tmp.pop();
        }
        
        return res;
        
        
    }
};
