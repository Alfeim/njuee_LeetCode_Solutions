/********************************************
作者:Alfeim
题目:单词缩写
时间消耗:88ms
解题思路:自定义排序准则 + 哈希表
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(const string &w1,const string &w2) const{
            int m = w1.size(),n = w2.size();     
            if(w1[0] < w2[0]) 
                return true;
            else if(w1[0] > w2[0]) 
                return false;
            
            if(w1[m-1] < w2[n-1]) 
                return true;
            else if(w1[m-1] > w2[n-1]) 
                return false;
            
            return m < n;      
        }
    };
    
    unordered_map<string,string> record;   //record记录映射关系
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> tmp(dict);
        vector<string> res;
      
        int n = tmp.size();

        //自定义排序准则,先按照首字母,再按照尾字母,最后按照长度
        sort(tmp.begin(),tmp.end(),cmp());
        
        //开始遍历,每次[leftm,right]区间内都是长度相同且首位字母相同的单词集合,只有集合内的单词可能映射不唯一
        
        for(int left = 0 ,right = -1; left < n && right < n;){
            
            while(tmp[left][0] == tmp[right+1][0] && tmp[left].back() == tmp[right+1].back() && tmp[left].size() == tmp[right+1].size()) {
                ++right;
                if(right == n-1) break;
            }
            
            Solve(tmp,left,right);
            
            left = right + 1;
        }
        
        
        for(auto i : dict){
            if(record.count(i)){
                res.push_back(record[i]);
                continue;
            }
            res.push_back(i);
        }
        
        
        return res;
        
    }
    
    //求最终集合内保证映射不唯一的前缀长度,如果只有一个单词显然前缀只需要为1即可
    void Solve(vector<string>& tmp,int left,int right){
        int len = tmp[left].size();
        
        if(len <= 3) 
            return;
        if(left == right){
            record[tmp[left]] = tmp[left][0] + to_string(len - 2) + tmp[left].back();
            return;
        }
        
        vector<bool> transformed(right - left + 1,false);
        unordered_map<string,int> prefixcount;
        
        for(int i = 1; i < len - 3 ; ++i){
            //先遍历一次
            for(int j = left ; j <= right ; ++j){
                if(transformed[j - left]) continue;
                prefixcount[tmp[j].substr(0,i+1)]++;
            }
            
            //然后查看哪些已经可以形成唯一映射
            for(int j = left ; j <= right ; ++j){
                if(transformed[j - left]) continue;
                if(prefixcount[tmp[j].substr(0,i+1)] == 1){
                    transformed[j - left] = true;
                    record[tmp[j]] = tmp[j].substr(0,i+1) + to_string(len - i - 2)  + tmp[j].back();
                }
            }
        }
        
        return;
    }
    
    
    
};
