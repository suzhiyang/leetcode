#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), l, r, i, j;
        if (m > n) return findMedianSortedArrays(b, a);
        l = 0, r = m;
        while (l <= r)
        {
            i = l + (r - l) / 2;
            j = (m + n + 1) / 2 - i;
            if (i < m && j > 0 && b[j - 1] > a[i]) l = i + 1;
            else if (i > 0 && j < n && a[i - 1] > b[j]) r = i - 1;
            else break;
        }
        int n1, n2;
        if (i == 0) n1 = b[j - 1];
        else if (j == 0) n1 = a[i - 1];
        else n1 = max(a[i - 1], b[j - 1]);
        if ((m + n) % 2) return n1;

        if (i == m) n2 = b[j];
        else if (j == n) n2 = a[i];
        else n2 = min(a[i], b[j]);
        return (n1 + n2) / 2.0;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
//         int m = a.size(), n = b.size();
//         int l = (m + n + 1) / 2, r = (m + n + 2) / 2;
//         return (findkth(a, b, 0, m, 0, n, l) + findkth(a, b, 0, m, 0, n, r)) / 2.0;
//     }
//     int findkth(vector<int> &a, vector<int> &b, int as, int m, int bs, int n, int k)
//     {
//         cout<<"---"<<m<<" "<<n<<":"<<k<<endl;
//         if (m > n) return findkth(b, a, bs, n, as, m, k);
//         if (m == 0) return b[bs + k - 1];
//         if (k == 1) return min(a[as], b[bs]);
        
//         int i = min(m, k / 2), j = k / 2;
//         if (a[as + i - 1] > b[bs + j - 1])
//             return findkth(a, b,
//                            as, i,
//                            bs + j, n - j,
//                            k - j);
//         else
//             return findkth(a, b,
//                            as + i, m - i,
//                            bs, j,
//                            k - i);
//     }
// };

int find_kth(int a[], int b[], int size_a, int size_b, int k){
      /* to maintain uniformaty, we will assume that size_a is smaller than size_b
                else we will swap array in call :) */
        if(size_a > size_b)
                return find_kth(b, a, size_b, size_a, k);
        /* Now case when size of smaller array is 0 i.e there is no elemt in one array*/
        if(size_a == 0 && size_b >0)
                return b[k-1]; // due to zero based index
        /* case where K ==1 that means we have hit limit */
        if(k ==1)
                return min(a[0], b[0]);

        /* Now the divide and conquer part */
        int i =  min(size_a, k/2) ; // K should be less than the size of array  
        int j =  min(size_b, k/2) ; // K should be less than the size of array  

        if(a[i-1] > b[j-1])
                // Now we need to find only K-j th element
                return find_kth(a, b+j, i, size_b -j, k-j);
        else
            return find_kth(a+i, b, size_a-i, j,  k-i);
}
int main()
{
    vector<int> a(2, 0), b(2, 0);
    a[0] = 1, a[1] = 2, b[0] = 3, b[1] = 4;
    Solution s;
    // cout<<s.findkth(a, b, 0, 2, 0, 2, 2)<<endl;
    // cout<<s.findkth(a, b, 0, 2, 0, 2, 3)<<endl;
    // cout<<s.findMedianSortedArrays(a, b)<<endl;
    a[0] = 1, a[1] = 2, b[0] = 1, b[1] = 1;
    int x[] = {1,2}, y[] = {1,1};
    cout<<s.findkth(a, b, 0, 2, 0, 2, 2)<<endl;
    cout<<find_kth(x, y, 2, 2, 2)<<endl;
    cout<<s.findkth(a, b, 0, 2, 0, 2, 3)<<endl;
    cout<<find_kth(x, y, 2, 2, 3)<<endl;
//    cout<<s.findMedianSortedArrays(a, b)<<endl;
}
