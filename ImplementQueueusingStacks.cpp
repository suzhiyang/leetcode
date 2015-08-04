#include <stack>

using namespace std;

class Queue {
private:
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> t;
        int m;
        while(!s.empty())
        {
            m = s.top();
            s.pop();
            t.push(m);
        }
        s.push(x);
        while(!t.empty())
        {
            m = t.top();
            t.pop();
            s.push(m);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();        
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
