class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int search_num=target-nums[i];
            if(mp.find(search_num)!=mp.end()){
                return {mp[search_num],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};
