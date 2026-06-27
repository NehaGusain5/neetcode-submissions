class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lMax=INT_MIN;
        int rMax=INT_MIN;
        int total=0;
        int left=0;
        int right=n-1;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]<lMax){
                    total+=lMax-height[left];
                }
                else{
                    lMax=height[left];
                }
                left++;
            }
            else{
                if(height[right]<rMax){
                    total+=rMax-height[right];
                }
                else{
                    rMax=height[right];
                }
                right--;
            }
        }
        return total;
    }
};
