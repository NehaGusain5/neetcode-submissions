class Solution {
public:
    int maxArea(vector<int>& heights) {
        
       int left=0;
       int n=heights.size();
       int right=n-1;
       int maxWater=INT_MIN;
       while(left<right){
        int w=right-left;
        int h=min(heights[left],heights[right]);
        int area=w*h;
        maxWater=max(maxWater,area);
        heights[left]<heights[right]?left++:right--;
       }
       return maxWater;
    }
};
