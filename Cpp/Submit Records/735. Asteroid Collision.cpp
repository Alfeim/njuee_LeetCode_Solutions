
/********************************************
作者:Alfeim
题目:行星碰撞
时间消耗:12ms
解题思路:栈
********************************************/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> tmp;
        for(auto i : asteroids){
            if(i > 0){
                tmp.push(i);
            }else{
                bool boom = false;
                int size = abs(i);
                while(!tmp.empty()){
                    if(tmp.top() < 0) break;
                    else if(size < tmp.top()){
                        boom = true;
                        break;
                    }else if(size == tmp.top()){
                        boom = true;
                        tmp.pop();
                        break;
                    }else{
                        tmp.pop();
                    }
                }
                if(!boom) tmp.push(i);
            }
        }
        int n = tmp.size();
        vector<int> res(n,0);
        int pos = n - 1;
        while(!tmp.empty()){
            res[pos] = tmp.top();
            tmp.pop();
            pos--;
        }
        
        return res;
    }
};
