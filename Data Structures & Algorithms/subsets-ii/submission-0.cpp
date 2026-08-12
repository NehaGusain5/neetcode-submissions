class Solution {
public:
    void recurSubset(vector<int>& ds,vector<vector<int>>& ans,int index,vector<int>& nums){
        ans.push_back(ds);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            recurSubset(ds,ans,i+1,nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());

        recurSubset(ds,ans,0,nums);

        return ans;
    }
};
