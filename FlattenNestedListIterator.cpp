#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class NestedInteger {
public:
    int m_integer;
    bool m_isinteger;
    vector<NestedInteger> m_v;

    NestedInteger(): m_isinteger(false)
    {
    }
    
    NestedInteger(int i): m_isinteger(true)
    {
        m_integer = i;
    };
    
    bool isInteger() const {return m_isinteger;}
    int getInteger() const {return m_integer;};
    const vector<NestedInteger> &getList() const
    {
        return m_v;
    };
};


class NestedIterator {
public:
    stack<pair<vector<NestedInteger>, int> > stk;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push(make_pair(nestedList, 0));
    }

    int next() {
        pair<vector<NestedInteger>, int> p = stk.top();
        ++stk.top().second;
        return p.first[p.second].getInteger();
    }

    bool hasNext() {
        while (!stk.empty())
        {
            pair<vector<NestedInteger>, int> p = stk.top();
            int pos = p.second;
            if (pos >= p.first.size())
            {
                stk.pop();
                continue;
            }
            NestedInteger ni = p.first[pos];
            if (ni.isInteger()) return true;
            else
            {
                ++stk.top().second;
                stk.push(make_pair(ni.getList(), 0));
            }
        }
        return false;
    }
};


int main()
{
    vector<NestedInteger> nestedList;
    NestedInteger ni;
    ni.m_v.push_back(NestedInteger(1));
    ni.m_v.push_back(NestedInteger(1));
    nestedList.push_back(ni);
    nestedList.push_back(NestedInteger(2));
    nestedList.push_back(ni);
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next()<<endl;
}
