class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss;
        long long n = numerator, d = denominator, i;
        if (n * d < 0) ss<<"-";
        if (n < 0) n = -n;
        if (d < 0) d = -d;
        ss<<n / d;
        n %= d;
        if (n == 0) return ss.str();
        ss<<".";
        vector<int> v;
        map<long long, int> h;
        while(true)
        {
            if (h.count(n)) break;
            h[n] = v.size();
            v.push_back(n * 10 / d);
            n = n * 10 % d;
        }
        for (i = 0; i < h[n]; ++i)
            ss<<v[i];
        if (n == 0) return ss.str();
        ss<<"(";
        for (; i < v.size(); ++i)
            ss<<v[i];
        ss<<")";
        return ss.str();
    }
};
