#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> m_stack;
    stack<int> m_min;
public:
    void push(int x) {
        m_stack.push(x);
        if (m_min.empty() || x <= m_min.top())
            m_min.push(x);
    }

    void pop() {
        int t = m_stack.top();
        m_stack.pop();
        if (t == m_min.top())
            m_min.pop();
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min.top();
    }
};

int main()
{
    MinStack ms;
    ms.push(3);
    cout<<ms.getMin()<<endl;
    ms.push(1);
    cout<<ms.getMin()<<endl;
    ms.push(2);
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.pop();
    cout<<ms.getMin()<<endl;
}
