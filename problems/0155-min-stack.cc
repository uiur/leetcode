// Runtime: 16 ms, faster than 96.77% of C++ online submissions for Min Stack.
// Memory Usage: 16.4 MB, less than 27.36% of C++ online submissions for Min Stack.

class MinStack {
public:
    vector<int> stack;
    vector<int> min_indexes;
    int min_val;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        int next_min_index;
        int top_index = stack.size() - 1;
        if (min_indexes.size() > 0) {
            next_min_index = val < getMin() ? top_index + 1 : min_indexes[top_index];
        } else {
            next_min_index = 0;
        }
        
            
        stack.push_back(val);
        min_indexes.push_back(next_min_index);
    }
    
    void pop() {
        stack.pop_back();
        min_indexes.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return stack[min_indexes[min_indexes.size() - 1]];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
