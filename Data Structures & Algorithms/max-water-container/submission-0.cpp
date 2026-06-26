class Solution {
public:
    int maxArea(vector<int>& heights) {
        
         int n=heights.size();
        int maxWater=INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w=j-i;
                int h=min(heights[i],heights[j]);
                int area=w*h;
                maxWater=max(maxWater,area);
            }
        }
        return maxWater;
    }
};
