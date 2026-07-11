class Solution {
public:
    bool isValid(int hrs,vector<int>& piles,int h){
        int totalhrs=0;

        for(int i=0;i<piles.size();i++){
             totalhrs+=(int)(piles[i]+hrs-1)/hrs;
            if(totalhrs>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        auto maxEle=*max_element(piles.begin(),piles.end());

        int high=(int) maxEle;
        int low=1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isValid(mid,piles,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
        
    }
};
