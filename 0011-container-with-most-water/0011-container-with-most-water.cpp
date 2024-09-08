class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int start = 0;
        int end = height.size() - 1;
        while(start < end){
            max_area = max(max_area, min(height[start], height[end]) * (end - start));
            if(height[start] < height[end]) start++;
            else end--;
        }
        return max_area;
    }
};