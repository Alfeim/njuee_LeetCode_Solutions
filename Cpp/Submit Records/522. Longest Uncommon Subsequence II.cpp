/********************************************
作者:Alfeim
题目:最长特殊序列2
时间消耗:4ms
解题思路:排序、双指针
********************************************/
class Solution {
public:

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](string &s1,string &s2){return s1.size() > s2.size();});
        int len = strs.size();
        for(int i = 0 ; i < len ; ++i){
            bool flag = true;
            for(int j = 0 ; j < len &&  strs[j].size() >= strs[i].size();j++){
                if(i != j && isSubs(strs[j],strs[i])){
                    flag = false;
                    break;
                }  
            }
            if(flag) return strs[i].size();
        }
        
        return -1;
    }

    
    bool isSubs(string &first,string &second){
        int m = first.size(),n = second.size();
        int i = 0 , j = 0; 
        for(; i < m && j < n;i++){
            if(first[i] == second[j]) j++;
        }
        return j == n;
    }

};
