class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int> temp(n+m);
        int left=0;
        int right=0;
        int index=0;

        while(left<n && right<m){
            if(nums1[left]<=nums2[right]){
                temp[index]=nums1[left];
                index++;
                left++;
            }
            else{
                temp[index]=nums2[right];
                index++;
                right++;
            }
        }
        while(left<n){
            temp[index]=nums1[left];
            index++;
            left++;
        }
        while(right<m){
            temp[index]=nums2[right];
            index++;
            right++;
        }
        int size=temp.size();
        if(size%2!=0){
            return static_cast<double>(temp[size/2]);
        }
        double num1=temp[(size/2)-1];
        double num2=temp[((size/2)+1)-1];
        return ((num1+num2)/2);
    }
};
