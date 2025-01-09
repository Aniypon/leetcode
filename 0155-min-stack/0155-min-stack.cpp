#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> stackData; 
    stack<int> minStack;  

public:
    MinStack() {
    }

    void push(int val) {
        stackData.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }

    void pop() {
        stackData.pop();
        minStack.pop();
    }

    int top() {
        return stackData.top();
    }

    int getMin() {
        return minStack.top();
    }
};
