#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> vec;
public:
    Solution()
    {
        vec.push_back("1");
        int i;
        for (i = 1; i < 30; ++i)
        {
            int j, c = 1;
            string str;
            for (j = 1; j <= vec[i - 1].size(); ++j)
            {
                if (j < vec[i - 1].size() && vec[i - 1][j] == vec[i - 1][j - 1]) ++c;
                else
                {
                    stringstream ss;
                    ss<<c;
                    str = str + ss.str() + vec[i - 1][j - 1];
                    c = 1;
                }
            }
            vec.push_back(str);
        }
    }
    
    string countAndSay(int n) {
        return vec[n - 1];
    }
};


int main()
{
    Solution s;
    cout<<s.countAndSay(1)<<endl;
    cout<<s.countAndSay(2)<<endl;
    cout<<s.countAndSay(3)<<endl;
    cout<<s.countAndSay(4)<<endl;
    cout<<s.countAndSay(30)<<endl;
}
