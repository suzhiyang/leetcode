#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> m_q;
public:
    // Push element x onto stack.
    void push(int x) {
        m_q.push(x);
        int i, t;
        for (i = 0; i < m_q.size() - 1; ++i)
        {
            t = m_q.front();
            m_q.pop();
            m_q.push(t);
        }
    }

    // Removes the element on top of the stack.
    void pop(void) {
        m_q.pop();
    }

    // Get the top element.
    int top(void) {
        return m_q.front();
    }

    // Return whether the stack is empty.
    bool empty(void) {
        return m_q.empty();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    int t;
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        cout<<t<<endl;
    }
}
