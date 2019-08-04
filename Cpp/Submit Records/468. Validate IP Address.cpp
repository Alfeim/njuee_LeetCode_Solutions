/********************************************
作者:Alfeim
题目:验证IP地址
时间消耗:4ms
解题思路:细节题
********************************************/
class Solution {
public:
    string validIPAddress(string IP) {
        if(isIPV4(IP))
            return "IPv4";
        
        if(isIPV6(IP))
            return "IPv6";
        
        return "Neither";
        
    }
    
    bool isIPV4(string IP){
        int n = IP.size();
        if(n > 15) return false;          //IPV4最多有4*3 + 3 = 15位
        int dots = 0;
        for(int i = 0 ; i < n ;){
           if(IP[i] == '.'){              //如果当前位是.就继续循环；
               if(i == n - 1 || !isdigit(IP[i+1])) return false;
               dots++;
               i++;
               continue;
           }else if(isdigit(IP[i])){      //连续数字不能超过3位,数值不能大于255,除单个0外数字开头不能为0
               string number;
               char firstnumber = IP[i];
               int bits = 0;
               while(isdigit(IP[i])) number += IP[i++],bits++;    
               if(bits > 3) return false;
               int cur = stoi(number);
               if( (cur > 255) || (cur > 0  && firstnumber == '0') || (cur == 0 && bits > 1))
                   return false;
           }else{
               return false;
           }         
        }
        return dots == 3;
    }
    
    
    bool isIPV6(string IP){
        int n = IP.size();
        if(n > 39) return false;
        int dots = 0;
        for(int i = 0 ; i < n ;){
            if(IP[i] == ':'){
                if(i == n - 1 || !valid(IP[i+1])) return false;
                dots++;
                i++;
                continue;
            }else if(valid(IP[i])){
                string number;
                int bits = 0;
                while(valid(IP[i])) number += IP[i++],bits++;
                if(bits > 4) return false;
            }else{
                return false;
            }
        }
        return dots == 7;
    }
    
    
    bool valid(char word){
        if( (word >= 'a' && word <= 'f') || (word >= 'A' && word <= 'F') || isdigit(word))
            return true;
        
        return false;
    }
  
};
