class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();

        sort(points.begin(), points.end());
        int count = 1;
        vector<int> prev = points[0];
        for (int i = 1; i < n; i++) {
            int currsp = points[i][0];
            int currep = points[i][1];

            int prevsp = prev[0];
            int prevep = prev[1];

            // no overlap
            if (currsp > prevep) {
                count++;
                prev = points[i];
            } else {
                prev[0] = max(currsp, prevsp);
                prev[1] = min(currep, prevep);
            }
        }
        return count;
    }
};