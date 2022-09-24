class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.emplace(-1);
        int n = heights.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            while (s.size() > 1 && heights[s.top()] >= heights[i]) {
                int p = s.top();
                s.pop();
                
                int area = heights[p] * (i - s.top() - 1);
                if (area > ret) ret = area;
            }
            s.emplace(i);
        }
        while (s.size() > 1) {
            int p = s.top();
            s.pop();
            int area = heights[p] * (n - s.top() - 1);
            if (area > ret) ret = area;
        }
        return ret;
    }
};