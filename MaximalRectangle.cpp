#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0) return 0;
        int i, j, r = 0;
        vector<int> v(matrix[0].size(), 0);
        for (i = 0; i < matrix.size(); ++i)
        {
            for (j = 0; j < v.size(); ++j)
                if (matrix[i][j] == '1') ++v[j];
                else {v[j] = 0; continue;}
            r = max(r, largestRectangleArea(v));
        }
        return r;
    }

    int largestRectangleArea(vector<int>& height) {
        stack<int> stk;
        int i, r = 0, area, tp;
        for (i = 0; i < height.size();)
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else
            {
                tp = stk.top();
                stk.pop();
                area = (stk.empty()?i:(i - stk.top() - 1)) * height[tp];
                r = max(r, area);
            }
        }
        while(!stk.empty())
        {
            tp = stk.top();
            stk.pop();
            area = ((stk.empty()?i:(i - stk.top() - 1))) * height[tp];
            r = max(r, area);
        }
        return r;
    }

};

int main()
{
    char a[][10] = {"01101",
                    "11010",
                    "01110",
                    "11110",
                    "11111",
                    "00000"};
    Solution s;
    vector<vector<char> > v(6, vector<char>());
    for (int i = 0; i < 6; ++i)
        v[i].assign(a[i], a[i] + 5);
    cout<<s.maximalRectangle(v)<<endl;
}
