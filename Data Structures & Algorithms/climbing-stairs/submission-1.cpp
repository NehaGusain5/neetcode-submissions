class Solution {
public:
    int numberSteps(int index,int n,vector<int>& dp){
        if(index==n){
            return 1;
        }
        if(index>n){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int oneStep=numberSteps(index+1,n,dp);
        int twoStep=numberSteps(index+2,n,dp);
        return dp[index]=oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return numberSteps(0,n,dp);
    }
};
