class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0, v1, v2;
        while(p1 < version1.size() || p2 < version2.size())
        {
            v1 = 0, v2 = 0;
            while(p1 < version1.size() && version1[p1] != '.')
                v1 = v1 * 10 + version1[p1++] - '0';
            while(p2 < version2.size() && version2[p2] != '.')
                v2 = v2 * 10 + version2[p2++] - '0';
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            ++p1, ++p2;
        }
        return 0;
    }
};
