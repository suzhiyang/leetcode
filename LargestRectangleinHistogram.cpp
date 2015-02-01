#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int i, t;
        int maxarea = 0, area;
        stack<int> s;
        height.push_back(0);
        for(i = 0; i < height.size(); ++i)
        {
            while(!s.empty() && height[i] < height[s.top()])
            {
                t = s.top();
                s.pop();
                area = height[t] * (s.empty() ? i : (i - s.top() - 1));
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
//    int a[] = {2,1,5,6,2,3};
    int a[] = {4,2,0,3,2,5};
//    int a[] = {1, 5, 3, 4};
//    int a[] = {6, 2, 5, 4, 5, 1, 6};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    cout<<s.largestRectangleArea(v)<<endl;
}
