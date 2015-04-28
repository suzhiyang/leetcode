#include <iostream>
#include <set>

class Solution {
public:
    int sum(int n)
    {
        int r = 0, t;
        while(n != 0)
        {
            t = n % 10;
            r += t * t;
            n /= 10;
        }
        return r;
    }
    
    bool isHappy(int n) {
        set<int> h;
        while(true)
        {
            n = sum(n);
            if (n == 1) return true;
            if (h.find(n) != h.end()) return false;
            h.insert(n);
        }
    }
};

