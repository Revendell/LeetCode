#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Iterator {
public:
    struct Data{
        vector<int> nums;
        int index;
    };
    Data* data=new Data();
    Iterator(const vector<int>& nums){
        data->index=-1;
        for(auto num:nums)
            data->nums.push_back(num);
    }
    Iterator(const Iterator& iter){
        this->data=iter.data;
    }
    // Returns the next element in the iteration.
    int next(){
        data->index++;
        return data->nums[data->index];
    }
    // Returns true if the iteration has more elements.
    bool hasNext() const{
        return data->index<static_cast<int>(data->nums.size());
    }
};
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    //next()可以返回队头元素，但会造成队头索引的移动
        //考的其实是：如何返回队头元素，但队头索引不动

	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if (Iterator::hasNext())
            cur = Iterator::next();
        else
            cur = -1;

	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    return cur;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int res = cur;
        if (Iterator::hasNext())
            cur = Iterator::next();
        else
            cur = -1;
        return res;
	}

	bool hasNext() const {
	    return cur != -1;
	}
private:
    int cur;
};
int main()
{
    const vector<int> nums{1,2,3};
    PeekingIterator peekIter(nums);
    cout<<peekIter.next()<<endl;
    cout<<peekIter.peek()<<endl;
    cout<<peekIter.next()<<endl;
    cout<<peekIter.next()<<endl;
    cout<<peekIter.hasNext()<<endl;
    return 0;
}
