class MinStack {
public:
    stack<int> stk, ms;
    void push(int x) {
        if (ms.empty() || ms.top() >= x) ms.push(x);
        stk.push(x);
    }

    void pop() {
        if (ms.top() == stk.top()) ms.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return ms.top();
    }
};
