class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=prices[0];
        for(int i=0;i<prices.size();i++){
            int cost=prices[i];
            minPrice=min(minPrice,prices[i]);
            maxPro=max(maxPro,cost-minPrice);
        }
        return maxPro;

        
    }
};
