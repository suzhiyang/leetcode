#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Based on "largest rectangle in histogram"
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        int i, j, maxarea = 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> v(col, 0);
        for(i = 0; i < row; ++i)
        {
            for(j = 0; j < col; ++j)
                if (matrix[i][j] == '1') v[j] += 1;
                else v[j] = 0;
            int area = largestrectangle(v);
            if (area > maxarea) maxarea = area;
        }
        return maxarea;
    }

    int largestrectangle(vector<int> &height)
    {
        int i, t, area, maxarea = 0;
        stack<int> s;
        height.push_back(0);
        for(i = 0; i < height.size(); ++i)
        {
            while(!s.empty() && height[i] < height[s.top()])
            {
                t = s.top();
                s.pop();
                int width = i;
                if (!s.empty()) width = i - s.top() - 1;
                area = height[t] * width;
                if (area > maxarea) maxarea = area;
            }
            s.push(i);
        }
        height.pop_back();
        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > m(5, vector<char>(4));
    char a[][4] = {{0,0,0,1},
                   {0,1,1,1},
                   {0,1,1,1},
                   {1,1,1,0},
                   {0,0,1,1}};
    int i, j;
    for(i = 0; i < 5; ++i)
    {
        for(j = 0; j < 4; ++j)
            a[i][j] += '0';
        m[i].assign(a[i], a[i] + 4);
    }
    cout<<s.maximalRectangle(m)<<endl;
    vector<vector<char> > r(1, vector<char>(4, '1'));
    cout<<s.maximalRectangle(r)<<endl;
    vector<vector<char> > c(1, vector<char>(1, '1'));
    cout<<s.maximalRectangle(c)<<endl;
    vector<vector<char> > e;
    cout<<s.maximalRectangle(e)<<endl;
}
