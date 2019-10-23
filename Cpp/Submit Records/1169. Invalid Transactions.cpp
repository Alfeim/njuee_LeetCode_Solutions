/********************************************
作者:Alfeim
题目:查询无效交易
时间消耗:56ms
解题思路:二分搜索
********************************************/
class Solution {
public:
    struct node{
        string city_name;
        string name;
        int time;
        int amount;
        int pos;
        node(string _city,string _name,
            int _time,int _amount,int _pos):city_name(_city),name(_name),time(_time),amount(_amount),pos(_pos){

            };

    };

    struct cmp{
        bool operator()(const node* n1,const node* n2) const{
            return n1->time < n2->time;
        }
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        
        int n = transactions.size();
        vector<bool> valid(n,true);
        vector<node*> records;

        for(int i = 0 ; i < n ; ++i){
            node *cur = CreateNode(transactions,i);
            records.push_back(cur);
        }

        sort(records.begin(),records.end(),cmp());
        vector<string> res;
        for(int i = 0 ; i < n ; ++i){
            if(records[i]->amount > 1000){
                valid[records[i]->pos] = false;        
            }
            int low = lower_border(records,records[i]->time,0,i-1);
            int high = upper_border(records,records[i]->time,i+1,n-1);
            bool flag = true;
            for(int j = low ; j <= high ; ++j){
                if(j == i) continue;
                if(abs(records[j]->time - records[i]->time) <= 60 && records[j]->city_name != records[i]->city_name && records[j]->name == records[i]->name){
                    flag = false;
                    valid[records[j]->pos] = false;
                }
            }
            if(!flag) valid[records[i]->pos] = false;
        }

        for(int i = 0 ; i < n ; ++i){
            if(!valid[i]) res.push_back(transactions[i]);
        }

        return res;
    }

    int lower_border(vector<node*>& records,int curtime,int low,int high){
        if(low >= high - 1) return low;
        
        int mid = (low + high)>>1;
        
        if(records[mid]->time < curtime - 60) return lower_border(records,curtime,mid+1,high);

        return lower_border(records,curtime,low,mid);
    }


    int upper_border(vector<node*>& records,int curtime,int low,int high){
        if(low >= high - 1) return high;

        int mid = (low + high)>>1;

        if(records[mid]->time > curtime - 60) return upper_border(records,curtime,low,mid-1);

        return upper_border(records,curtime,mid,high);

    }

    node* CreateNode(vector<string> &transactions,int pos){
        string city_name;
        string name;
        int time;
        int amount;
        int n = transactions[pos].size();
        int dotcount = 0;
        for(int i = 0 ; i < n ; ){
            if(transactions[pos][i] == ',') {
                i++;
                dotcount++;
            }
            else{
                string tmp;
                while(i < n && transactions[pos][i] != ',') tmp += transactions[pos][i++];
                if(dotcount == 0) name = tmp;
                else if(dotcount == 1) time = stoi(tmp);
                else if(dotcount == 2) amount = stoi(tmp);
                else city_name = tmp;
            }
        }
        node* cur = new node(city_name,name,time,amount,pos);
        return cur;
    }
};
