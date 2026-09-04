class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int farthest=0;
        int current=0;
        int n=nums.size();
        if(n==1){return 0;}
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==current){
                current=farthest;
                jumps++;
            }
        }
        return jumps;
    }
};
