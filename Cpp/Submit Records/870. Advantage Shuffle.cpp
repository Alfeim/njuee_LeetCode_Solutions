/********************************************
作者:Alfeim
题目:优势洗牌
时间消耗:200ms
解题思路:排序、二分查找
********************************************/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int,int> records;
        vector<int> res;
        for(auto i : A) records[i]++;
        
        for(auto i : B){
            auto it = records.lower_bound(i);
            
            if(it->first == i) it++;
            
            if(it == records.end()){
                auto begin = records.begin();
                res.push_back(begin->first);
                begin->second--;
                if(begin->second == 0) records.erase(begin);
            }else{
                res.push_back(it->first);
                it->second--;
                if(it->second == 0) records.erase(it);
            }
            
        }
        
        return res;
        
    }
};
