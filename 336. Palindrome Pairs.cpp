/********************************************
作者:Alfeim
题目:回文对
时间消耗:502ms
解题思路:利用回文的性质,寻找切割点
********************************************/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> records;
        set<int> Lengh;
        int m = words.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < m ; ++i){
            records[words[i]] = i; 
            Lengh.insert(words[i].size());
        }
        
        for(auto i : words){
            string tmp1 = i;
            reverse(tmp1.begin(),tmp1.end());
            int n = i.size();
            
            if(records.count(tmp1) > 0 && records[i] != records[tmp1])
                res.push_back({records[i],records[tmp1]});
            
            for(int j = 0 ; j <= n ; j++){
                bool flag1 = Lengh.count(j) > 0;
                bool flag2 = Lengh.count(n-j) > 0;
                
                //情况2,分割点的后半部分是回文,前半部分的翻转在记录里
                if(flag1){
                    if(isPalind(i.substr(j)) && j < n){
                        string tmp2 = i.substr(0,j);
                        reverse(tmp2.begin(),tmp2.end());
                        if(records.count(tmp2) > 0)
                            res.push_back({records[i],records[tmp2]});
                    }
                }
                
                 //情况2,分割点的前半部分是回文,后半部分的翻转在记录里
                if(flag2){
                    if(isPalind(i.substr(0,j)) && j > 0){
                        string tmp2 = i.substr(j);
                        reverse(tmp2.begin(),tmp2.end());
                        if(records.count(tmp2) > 0)
                            res.push_back({records[tmp2],records[i]});
                    }
                }
            }
        }
        
        return res;
    }
    
    
    bool isPalind(string tmp){
        int n = tmp.size();
        for(int i = 0,j = n - 1; i < j ;){
            if(tmp[i++] != tmp[j--])
                return false;
        }
        
        return true;
    }
    
};
