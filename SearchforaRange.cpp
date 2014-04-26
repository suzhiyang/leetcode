#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left, right, mid;
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (A[mid] == target) break;
            if (A[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        if (A[mid] != target) return vector<int>(2, -1);
        // Binary search for left bound and right bound
        vector<int> r;
        int m = mid;
        left = 0;
        right = m;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (A[mid] < target && A[mid + 1] == target) break;
            if (A[mid] == target) right = mid - 1;
            else left = mid + 1;
        }
        if (left <= right) r.push_back(mid + 1);
        else r.push_back(mid);
        left = m;
        right = n - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (A[mid] > target && A[mid - 1] == target) break;
            if (A[mid] == target) left = mid + 1;
            else right = mid - 1;
        }
        if (left <= right) r.push_back(mid - 1);
        else r.push_back(mid);
        return r;
    }
};

int main()
{
    int a[] = {5, 7, 7, 8, 8, 10, 12};
    Solution s;
    vector<int> r = s.searchRange(a, 7, 8);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;
    r = s.searchRange(a, 7, 3);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;

    int b[] = {1};
    r = s.searchRange(b, 1, 0);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;
    r = s.searchRange(b, 1, 1);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;

    int c[] = {2,2};
    r = s.searchRange(c, 2, 2);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;

    int d[] = {1,4};
    r = s.searchRange(d, 2, 4);
    cout<<"["<<r[0]<<","<<r[1]<<"]"<<endl;
}
