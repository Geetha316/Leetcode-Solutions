class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = 0;
        int maxArea = 0;

        for (auto d : dimensions) {
            int l = d[0];
            int w = d[1];

            int diagonal = l * l + w * w;
            int area = l * w;

            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
            else if (diagonal == maxDiagonal) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};