class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0, r = height.size()-1, ans = 0;
        while(l<=r)
        {
            int h = min(height[l], height[r]);
            ans = max(ans, h*(r-l));
            (height[l]<=height[r]) ? l++ : r--;
        }
        return ans;
    }
};