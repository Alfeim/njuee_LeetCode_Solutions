/********************************************
作者:Alfeim
题目:整数转英文表示
时间消耗:12ms
解题思路:细节题,递归
********************************************/
class Solution {
public:
    //billion = 0;
    //million = 1;
    //thousand = 2;
    vector<string> res;
    unordered_map<int,string> dict;
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        dict[1] = "One";
        dict[2] = "Two";
        dict[3] = "Three";
        dict[4] = "Four";
        dict[5] = "Five";
        dict[6] = "Six";
        dict[7] = "Seven";
        dict[8] = "Eight";
        dict[9] = "Nine";
        dict[10] = "Ten";
        dict[11] = "Eleven";
        dict[12] = "Twelve";
        dict[13] = "Thirteen";
        dict[14] = "Fourteen";
        dict[15] = "Fifteen";
        dict[16] = "Sixteen";
        dict[17] = "Seventeen";
        dict[18] = "Eighteen";
        dict[19] = "Nineteen";
        dict[20] = "Twenty";
        dict[30] = "Thirty";
        dict[40] = "Forty";
        dict[50] = "Fifty";
        dict[60] = "Sixty";
        dict[70] = "Seventy";
        dict[80] = "Eighty";
        dict[90] = "Ninety";
        
        Solve(num);
        string ans;
        for(int i = 0 ; i < res.size();++i){
            ans += res[i];
            if(i != res.size() - 1)
                ans += " ";
        }
        return ans;
    }
    
    void Solve(int num){
        if(num == 0)
            return; 
        
        int basic = 1; 
        
        if(num >= 1000000000)
            basic = 1000000000;
        else if(num >= 1000000)
            basic = 1000000;
        else if(num >= 1000)
            basic = 1000;
            
        int count = num/basic;
        int Hcount = count/100;
        int Lcount = count - 100*Hcount;
        
        
        if(Hcount > 0){
            res.push_back(dict[Hcount]);
            res.push_back("Hundred");
        }
        
        if(dict.count(Lcount) > 0){
            res.push_back(dict[Lcount]);
        }else{
            int Tcount = Lcount/10;
            if(Tcount > 0)
                res.push_back(dict[Tcount*10]);
            int last = Lcount % 10;
            if(Lcount > 0)
                res.push_back(dict[last]);
        }
        
        if(basic == 1000)
            res.push_back("Thousand");
        else if(basic == 1000000 )
            res.push_back("Million");
        else if(basic == 1000000000)
            res.push_back("Billion");
        
        Solve(num - basic * count);
    }
    
};
