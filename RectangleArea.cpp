class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x, y, z, w, inter = 0;
        x = max(A, E); y = max(B, F);
        z = min(C, G); w = min(D, H);
        if (z > x && w > y) inter = (z - x) * (w - y);
        return (C - A) * (D - B) + (G - E) * (H - F) - inter;
    }
};
