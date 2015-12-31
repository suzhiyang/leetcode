class Stack {
public:
    queue<int> q1, q2;
    // Push element x onto stack.
    void push(int x) {
        queue<int> *fq = &q1;
        if (fq->empty()) fq = &q2;
        fq->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> *fq = &q1, *eq = &q2;
        if (fq->empty()) swap(fq, eq);
        while(fq->size() > 1)
        {
            eq->push(fq->front());
            fq->pop();
        }
        fq->pop();
    }

    // Get the top element.
    int top() {
        queue<int> *fq = &q1, *eq = &q2;
        if (fq->empty()) swap(fq, eq);
        while(fq->size() > 1)
        {
            eq->push(fq->front());
            fq->pop();
        }
        int r = fq->front();
        eq->push(r);
        fq->pop();
        return r;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
