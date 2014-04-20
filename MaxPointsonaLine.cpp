#include <iostream>
#include <map>
#include <vector>

using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() == 0) return 0;
        map<double, int> slopemap;
        int i, j, max = 0;
        double k;
        for (i = 0; i < points.size(); ++i)
        {
            slopemap.clear();
            int dup = 0, y = 0;
            int pmax = 0;
            for (j = i + 1; j < points.size(); ++j)
            {
                if (points[i].x == points[j].x && points[i].y == points[j].y) ++dup;
                else if (points[i].x == points[j].x && points[i].y != points[j].y) ++y;
                else
                {
                    k = ((double)(points[j].y - points[i].y)) / (points[j].x - points[i].x);
                    if (slopemap.find(k) != slopemap.end()) ++slopemap[k];
                    else
                    {
                        slopemap.insert(make_pair(k, 1));
                    }
                    if (slopemap[k] > pmax) pmax = slopemap[k];
                }
            }
            if (y + dup > max) max = y + dup;
            if (pmax + dup > max) max = pmax + dup;
        }
        return max + 1;
    }
};

int main()
{
    vector<Point> points;
    points.push_back(Point(0,0));
    points.push_back(Point(1,1));
    points.push_back(Point(0,0));
//     points.push_back(Point(1,1));
//     points.push_back(Point(1,2));
//     points.push_back(Point(1,1));
//     points.push_back(Point(1,3));
//     points.push_back(Point(2,1));
//     points.push_back(Point(2,2));
//     points.push_back(Point(3,3));
//     points.push_back(Point(3,1));
    Solution s;
    cout<<s.maxPoints(points)<<endl;
    return 0;
}
