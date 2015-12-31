class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxarea = 0, h;
        while(l < r)
        {
            h = min(height[l], height[r]);
            maxarea = max(maxarea, (r - l) * h);
            while(height[l] <= h && l < r) ++l;
            while(height[r] <= h && l < r) --r;
        }
        return maxarea;
    }
};
