class Solution {
public:
    void combSum(int index,int n,vector<vector<int>>& ans,vector<int>& vec,              vector<int>&nums, int target){
        if(index==n){
            if(target==0){
                ans.push_back(vec);
            }
            return;
        }
        
        if(nums[index]<=target) 
        {   vec.push_back(nums[index]);
            combSum(index,n,ans,vec,nums,target-nums[index]);
            vec.pop_back();
        }
        combSum(index+1,n,ans,vec,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> vec;
        vector<vector<int>> ans;

        combSum(0,n,ans,vec,nums,target);

        return ans;
        
    }
};
