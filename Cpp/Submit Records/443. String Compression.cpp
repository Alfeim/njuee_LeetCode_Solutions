/********************************************
作者:Alfeim
题目:压缩字符串
时间消耗:12ms
解题思路:双指针
********************************************/
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty())
            return 0;
        
        int n = chars.size();
        int first = 0 , second = 0;
        for(;first < n && second < n ;){
            int last = second;
            swap(chars[first],chars[second]);
            ++second;
            while(second < n && chars[second] == chars[first]) ++second; 
            int distance = second  - last;
            string dis = to_string(distance);
            first++;
            if(distance > 1){
                for(auto i : dis){
                    chars[first] = i;
                    first++;
                }
            }
        }
        
        return first;
        
    }
};
