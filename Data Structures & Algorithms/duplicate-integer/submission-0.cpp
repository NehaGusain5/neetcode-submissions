class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }

        for(auto it:nums){
            if(mpp[it]>1) return true;
        }
        return false;
    }
};