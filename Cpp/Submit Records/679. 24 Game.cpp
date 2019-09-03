/********************************************
作者:Alfeim
题目:24点游戏
时间消耗:20ms
解题思路:DFS回溯
********************************************/

//方法1
//一共四个数,第一次选两个数进行一次运算,然后得到三个数
//第二次再选两个数运算,得到两个数
//第三次选两个数运算得到一个数,此时即为答案

class Solution {
public:
    bool flag;
    bool judgePoint24(vector<int>& nums) {
        flag = false;
        sort(nums.begin(),nums.end());
        do{
            dfs(nums,0,3);
        }while(!flag && next_permutation(nums.begin(),nums.end()));
        return flag;
    }
 
    vector<pair<int,int>> dfs(vector<int>& nums,int begin,int end){
        pair<int,int> tmp1(1,1);
        pair<int,int> tmp2(1,1);
        pair<int,int> tmp3(1,1);
        pair<int,int> tmp4(1,1);
        vector<pair<int,int>> res;
        if(begin >= end) return {{nums[end],1}};
        for(int pos = begin ; pos <= end - 1 ; ++pos){    
            auto v1 = dfs(nums,begin,pos);
            auto v2 = dfs(nums,pos+1,end);
            for(auto i : v1){
                for(auto j : v2){
                    if(i.second == j.second){
                        tmp1.first = i.first + j.first;
                        tmp2.first = i.first - j.first;
                        tmp1.second = i.second; 
                        tmp2.second = i.second;
                    }else{
                        tmp1.first = i.first * j.second + j.first * i.second;
                        tmp2.first = i.first * j.second - j.first * i.second;
                        tmp1.second = i.second * j.second;
                        tmp2.second = i.second * j.second;
                    }
                    
                    tmp3.first = i.first * j.first;
                    tmp3.second = i.second * j.second;
                    
                    res.push_back(tmp1);
                    res.push_back(tmp2);
                    res.push_back(tmp3);
                    
                    if(j.first > 0){
                        tmp4.first = i.first * j.second;
                        tmp4.second = i.second * j.first;
                        res.push_back(tmp4);
                    }
                    
                    if( begin == 0 && end == 3){
                         if(tmp1.first % tmp1.second == 0 && tmp1.first / tmp1.second == 24) flag = true;
                         if(tmp2.first % tmp2.second == 0 && tmp2.first / tmp2.second == 24) flag = true;
                         if(tmp3.first % tmp3.second == 0 && tmp3.first / tmp3.second == 24) flag = true;
                         if(tmp4.first % tmp4.second == 0 && tmp4.first / tmp4.second == 24) flag = true;
                         if(flag) break;
                    }         
                }
            }
        }
        return res; 
    }
    
    
    vector<pair<int,int>> Solve(int step,vector<bool> visited,vector<int> &nums){
        vector<pair<int,int>> res;
        pair<int,int> tmp1(1,1);
        pair<int,int> tmp2(1,1);
        pair<int,int> tmp3(1,1);
        pair<int,int> tmp4(1,1);
        for(int i = 0 ; i < 4 ; ++i){
            if(!visited[i]){
                if(step == 3) return {{nums[i],1}};  
                visited[i] = true;
                auto TempRes = Solve(step+1,visited,nums);
                for(auto t : TempRes){
                    tmp1.first = nums[i] * t.second + t.first;
                    tmp1.second = nums[i] * t.second;
                    
                    tmp2.first = nums[i] * t.second - t.first;
                    tmp2.second = nums[i] * t.second;
                    
                    tmp3.first = nums[i] * t.first;
                    tmp3.second = nums[i] * t.second;
                    
                    res.push_back(tmp1);
                    res.push_back(tmp2);
                    res.push_back(tmp3);
                    
                    if(t.first > 0){
                        tmp4.first = nums[i] * t.second;
                        tmp4.second = t.first;
                        res.push_back(tmp4);
                    }
                    
                    if(step == 0){
                         if(tmp1.first % tmp1.second == 0 && tmp1.first / tmp1.second == 24) flag = true;
                         if(tmp2.first % tmp2.second == 0 && tmp2.first / tmp2.second == 24) flag = true;
                         if(tmp3.first % tmp3.second == 0 && tmp3.first / tmp3.second == 24) flag = true;
                         if(t.first > 0 && tmp4.first % tmp4.second == 0 && tmp4.first / tmp4.second == 24) flag = true;
                         if(flag) break; 
                    } 
                }
                visited[i] = false;
            }     
        }

        return res;
  
    }
      
};


//方法2:按照 241. 为运算表达式设计优先级 的计算方法来
//注意为了确保所有情况需要对输入进行全排列
class Solution {
public:
    bool flag;
    bool judgePoint24(vector<int>& nums) {
        flag = false;
        sort(nums.begin(),nums.end());
        do{
            dfs(nums,0,3);
        }while(!flag && next_permutation(nums.begin(),nums.end()));
        return flag;
    }
 
    vector<pair<int,int>> dfs(vector<int>& nums,int begin,int end){
        pair<int,int> tmp1(1,1);
        pair<int,int> tmp2(1,1);
        pair<int,int> tmp3(1,1);
        pair<int,int> tmp4(1,1);
        vector<pair<int,int>> res;
        if(begin >= end) return {{nums[end],1}};
        for(int pos = begin ; pos <= end - 1 ; ++pos){    
            auto v1 = dfs(nums,begin,pos);
            auto v2 = dfs(nums,pos+1,end);
            for(auto i : v1){
                for(auto j : v2){
                    if(i.second == j.second){
                        tmp1.first = i.first + j.first;
                        tmp2.first = i.first - j.first;
                        tmp1.second = i.second; 
                        tmp2.second = i.second;
                    }else{
                        tmp1.first = i.first * j.second + j.first * i.second;
                        tmp2.first = i.first * j.second - j.first * i.second;
                        tmp1.second = i.second * j.second;
                        tmp2.second = i.second * j.second;
                    }
                    
                    tmp3.first = i.first * j.first;
                    tmp3.second = i.second * j.second;
                    
                    res.push_back(tmp1);
                    res.push_back(tmp2);
                    res.push_back(tmp3);
                    
                    if(j.first > 0){
                        tmp4.first = i.first * j.second;
                        tmp4.second = i.second * j.first;
                        res.push_back(tmp4);
                    }
                    
                    if( begin == 0 && end == 3){
                         if(tmp1.first % tmp1.second == 0 && tmp1.first / tmp1.second == 24) flag = true;
                         if(tmp2.first % tmp2.second == 0 && tmp2.first / tmp2.second == 24) flag = true;
                         if(tmp3.first % tmp3.second == 0 && tmp3.first / tmp3.second == 24) flag = true;
                         if(tmp4.first % tmp4.second == 0 && tmp4.first / tmp4.second == 24) flag = true;
                         if(flag) break;
                    }         
                }
            }
        }
        return res; 
    }
  
};
