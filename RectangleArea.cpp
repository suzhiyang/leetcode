#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x = 0, y = 0;
        if (min(C,G) > max(A,E)) x = min(C,G) - max(A,E);
        if (min(D,H) > max(B,F)) y = min(D,H) - max(B,F);
        return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
    }
};

int main()
{
    Solution s;
    cout<<s.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1)<<endl;
}
