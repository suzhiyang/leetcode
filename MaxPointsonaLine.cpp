class Solution {
public:
    int gcd(int a, int b)
    {
        int c;
        while(a != 0)
        {
            c = a;
            a = b % a;
            b = c;
        }
        return b;
    }
    
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) return 0;
        int i, j, r = 1;
        for (i = 0; i < points.size(); ++i)
        {
            map<pair<int, int>, int> h;
            int cnt = 1, lmax = 0;
            for (j = i + 1; j < points.size(); ++j)
            {
                if (points[j].x == points[i].x && points[j].y == points[i].y)
                {
                    ++cnt; continue;
                }
                int a, b, g;
                a = points[j].y - points[i].y;
                b = points[j].x - points[i].x;
                if (a && b)
                {
                    g = gcd(a, b);
                    a /= g; b /= g;
                }
                else if (a != 0 && b == 0) a = 1;
                else if (a == 0 && b != 0) b = 1;
                lmax = max(lmax, ++h[make_pair(a, b)]);
            }
            r = max(r, lmax + cnt);
        }
        return r;
    }
};
