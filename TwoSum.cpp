#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> nummap;
        map<int, int>::iterator it;
        vector<int> r;
        int i;
        for(i = 0; i < numbers.size(); ++i)
            nummap.insert(make_pair(numbers[i], i));
        for(i = 0; i < numbers.size(); ++i)
        {
            it = nummap.find(target - numbers[i]);
            if (it != nummap.end() && i != it->second)
            {
                r.push_back(i + 1);
                r.push_back(it->second + 1);
                if (i > it->second) swap(r[0], r[1]);
                break;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    int a[] = {2, 7, 15, 11};
    vector<int> numbers(a, a + sizeof(a) / 4);
    vector<int> r = s.twoSum(numbers, 9);
    cout<<r[0]<<":"<<r[1]<<endl;
}
