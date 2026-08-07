class Solution {
public:
    int maxAmount(int index,int n,vector<int>& nums,vector<int>& dp){
        if(index==n-1) return nums[index];
        if(index>=n) return 0;

        if(dp[index]!=-1) return dp[index];

        int pick=nums[index]+maxAmount(index+2,n,nums,dp);
        int notPick=0+maxAmount(index+1,n,nums,dp);

        return dp[index]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,0);

        dp[n-1]=nums[n-1];

        for(int index=n-2;index>=0;index--){
            int pick=nums[index];

            if(index+2<n) pick+=dp[index+2];
            int notPick=0+dp[index+1];

           dp[index]=max(pick,notPick);
        }

        return dp[0];
        // return maxAmount(0,n,nums,dp);
    }
};
