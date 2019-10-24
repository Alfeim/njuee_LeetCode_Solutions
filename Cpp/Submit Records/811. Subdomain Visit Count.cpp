/********************************************
作者:Alfeim
题目:子域名访问次数
时间消耗:20ms
解题思路:哈希表
********************************************/
class Solution {
public:
    unordered_map<string,int> record;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        for(auto i : cpdomains){
            Solve(i);
        }

        for(auto i : record){
            res.push_back(to_string(i.second) + " " + i.first);
        }
        return res;
    }

    void Solve(string str){
        int n = str.size();
        int i = 0;
        int count = 0;
        
        while(i < n && isdigit(str[i])){
            count *= 10;
            count += str[i++] - '0';
        }

        while(str[i] == ' ') i++;
        while(i < n ){
            if(str[i] == '.'){
                i++;
            }else{
                record[str.substr(i)] += count;
                while(i < n && str[i] != '.') i++;
            }
        }

    }


};
