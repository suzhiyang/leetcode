class Solution {
public:
    int countDigitOne(int n)
    {
        int c = 0, l;
        for (long long m = 1; m <= n; m *= 10)
        {
            long long a = n / m, b = n % m;
            l = a % 10;
            if (l == 0) c += a / 10 * m;
            else if (l == 1) c += a / 10 * m + b % m + 1;
            else c += (a / 10 + 1) * m;
        }
        return c;
    }
};

// class Solution {
// public:
//     int countDigitOne(int n) {
//         long long p, q, f = 10, c = 0, l;
//         while(f / 10 <= n)
//         {
//             p = n / f;
//             q = n % f;
//             l = q / (f / 10);
//             if (l == 0) c += p * f / 10;
//             else if (l == 1) c += p * f / 10 + q % (f / 10) + 1;
//             else c += (p + 1) * f / 10;
//             f *= 10;
//         }
//         return c;
//     }
// };
