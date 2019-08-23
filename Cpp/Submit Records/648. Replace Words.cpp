/********************************************
作者:Alfeim
题目:单词替换
时间消耗:124ms
解题思路:哈希表
********************************************/
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> record(dict.begin(),dict.end());
        string res;
        int n = sentence.size();
        for(int i = 0 ; i < n ; ){
            if(sentence[i] == ' '){
                res += ' ';
                i++;
                continue;
            }else{
                string tmp; 
                while(i < n && sentence[i] != ' '){
                    tmp += sentence[i++];
                    if(record.count(tmp)) break;
                }
                while(i < n && sentence[i] != ' ') i++;
                res += tmp;
            }
        }
        
        return res;
        
        
    }
};
