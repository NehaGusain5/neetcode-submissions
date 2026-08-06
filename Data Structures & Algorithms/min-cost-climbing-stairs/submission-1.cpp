class Solution {
public:
    int minCost(int index,int n,vector<int>& cost,vector<int>& dp){
        if(index==n-1) return cost[index];
        if(index>=n) return 0;

        if(dp[index]!=-1) return dp[index];

        int oneStep=cost[index]+minCost(index+1,n,cost,dp);
        int twoStep=cost[index]+minCost(index+2,n,cost,dp);

        return dp[index]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);

        return min(minCost(0,n,cost,dp),minCost(1,n,cost,dp));
    }
};
