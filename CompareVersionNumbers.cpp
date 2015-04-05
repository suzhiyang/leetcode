#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int i, c = 0;
        for (i = 0; i < version1.size(); ++i)
        {
            if (version1[i] == '.')
            {
                v1.push_back(c);
                c = 0;
            }
            else c = c * 10 + version1[i] - '0';
        }
        v1.push_back(c);
        c = 0;
        for (i = 0; i < version2.size(); ++i)
        {
            if (version2[i] == '.')
            {
                v2.push_back(c);
                c = 0;
            }
            else c = c * 10 + version2[i] - '0';
        }
        v2.push_back(c);
        i = 0;
        while(i < v1.size() && i < v2.size())
        {
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
            ++i;
        }
        if (i == v1.size())
        {
            for(; i < v2.size(); ++i)
                if (v2[i] > 0) return -1;
            return 0;
        }
        else if (i == v2.size())
        {
            for(; i < v1.size(); ++i)
                if (v1[i] > 0) return 1;
            return 0;
        }
    }
};

int main()
{
    
}
