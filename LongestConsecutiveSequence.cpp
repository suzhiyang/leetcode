#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Replace set with unordered_set
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int i;
        set<int> hashset;
        for (i = 0; i < num.size(); ++i)
            hashset.insert(num[i]);
        int max = 1;
        for (i = 0; i < num.size(); ++i)
        {
            set<int>::iterator it;
            it = hashset.find(num[i]);
            if (it != hashset.end())
            {
                int t = 1, n = num[i];
                hashset.erase(n);
                while(true)
                {
                    if (hashset.find(++n) != hashset.end())
                    {
                        hashset.erase(n);
                        ++t;
                    }
                    else break;
                }
                n = num[i];
                while(true)
                {
                    if (hashset.find(--n) != hashset.end())
                    {
                        hashset.erase(n);
                        ++t;
                    }
                    else break;
                }
                if (t > max) max = t;
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(a, a + 6);
    cout<<s.longestConsecutive(num)<<endl;
}
