#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int candidate, counter = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            if (counter == 0)
            {
                candidate = num[i];
                ++counter;
            }
            else
            {
                if (candidate == num[i])
                    ++counter;
                else --counter;
            }
        }
        return candidate;
    }
};

int main()
{
    Solution s;
    int a[] = {3,3,4};
    vector<int> v(a, a + 3);
    cout<<s.majorityElement(v)<<endl;
}
