/********************************************
作者:Alfeim
题目:顶端迭代器
时间消耗:8ms
解题思路:用一个栈来存储临时的peek;如果当前栈非空,next
时就出栈,否则调用父类的next;
********************************************/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    stack<int> Tmp;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(Tmp.empty()){
            auto cur = Iterator::next();
            Tmp.push(cur);
        }
        return Tmp.top();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(!Tmp.empty()){
            auto cur = Tmp.top();
            Tmp.pop();
            return cur;
        } 
        return Iterator::next();
	}

	bool hasNext() const {
        if(Tmp.empty() && !Iterator::hasNext())
            return false;
        return true;
	    
	}
};
