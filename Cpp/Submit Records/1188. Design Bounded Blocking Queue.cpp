/********************************************
作者:Alfeim
题目:设计阻塞队列
时间消耗:40ms
解题思路:条件变量
********************************************/
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity):Capacity(capacity),Size(0){
        deqReadyFlag = false;
        if(Capacity <= 0 ){
            enqReadyFlag = false;
        }else
            enqReadyFlag = true;
    }
    
    void enqueue(int element) {

        
        std::unique_lock<std::mutex> ul(enqReadymutex);
        enqReadyConvar.wait(ul,[this]{return enqReadyFlag;});        

        List.push_front(element);
        Size++;

        if(Size >= Capacity){
            enqReadyFlag = false;
            enqReadyConvar.notify_one();
        }

        if(Size > 0){
            deqReadyFlag = true;
            deqReadyConvar.notify_one();
        }
    }
    
    int dequeue(){
        {
            std::unique_lock<std::mutex> ul(deqReadymutex);
            deqReadyConvar.wait(ul,[this]{return deqReadyFlag;});
        }

        int last = List.back();
        List.pop_back();
        Size--;

        if(Size < Capacity){
            enqReadyFlag = true;
             enqReadyConvar.notify_one();
        }
        
        if(Size == 0){ 
            deqReadyFlag = false;
            deqReadyConvar.notify_one();
        }
        return last;
    }
    
    int size() {
        return Size;
    }

private:
    bool enqReadyFlag,deqReadyFlag;
    std::mutex enqReadymutex,deqReadymutex;
    condition_variable enqReadyConvar,deqReadyConvar;
    int Capacity,Size;
    deque<int> List;
};
