class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start(0), end(height.size()-1);

        int res = INT_MIN;

        while(start < end){
            int area = min(height[start], height[end])*(end-start);
            res = max(res, area);

            if(height[start]<=height[end]) start++;
            else end--;
        }

        return res;
    }
};