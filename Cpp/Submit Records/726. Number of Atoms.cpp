/********************************************
作者:Alfeim
题目:原子的数目
时间消耗:0ms
解题思路:细节题
********************************************/
class Solution {
public:
    struct cmp{
      bool operator()(const string &ele1,const string &ele2 ) const{
          int m = ele1.size(), n = ele2.size();
          int i = 0 , j = 0;
          while(i < m && j < n ){
              if(ele1[i] < ele2[j]) return true;
              else if(ele1[i] > ele2[j]) return false;
              i++;
              j++;
          }
          return i == m; 
      }
        
    };
    string countOfAtoms(string formula) {
        if(formula.empty()) return "";
        
        unordered_map<string,int> counts;
        map<string,int,cmp> rescounts;
        int pos = 0;
        Solve(formula,pos,counts);
        string res;
        for(auto i : counts) rescounts[i.first] = i.second;
        
        for(auto i : rescounts){
            res += i.first;
            if(i.second > 1) res += to_string(i.second);
        }
        
        
        return res;
    }
    
    void Solve(string &formula,int &pos,unordered_map<string,int>& tmp_counts){
        int n = formula.size();
        for(; pos < n ;){
            
            if(formula[pos] == '('){
                //如果遇到左括号就递归求解
                unordered_map<string,int> M;
                Solve(formula,++pos,M);
                
                int multi = 1;
                string number;
                while(pos < n && isdigit(formula[pos])) number += formula[pos++];
                
                if(!number.empty()) multi = stoi(number);
                for(auto i : M) tmp_counts[i.first] += multi*i.second;
                
            }else if(formula[pos] == ')'){
                //如果遇到右括号就返回
                pos++;
                return;
            }else{
                //否则就添加对应元素的个数
                string element;
                string number;
                int multi = 1;
                element += formula[pos++];
                while(pos < n && (formula[pos] >= 'a' && formula[pos] <= 'z') ) element += formula[pos++];
                while( pos < n && isdigit(formula[pos]) ) number += formula[pos++];
                if(!number.empty()) multi = stoi(number);
                tmp_counts[element] += multi;
            }
        }
        
        return;
        
    }
    
};
