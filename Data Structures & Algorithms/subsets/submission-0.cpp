class Solution {
public:
    void numSubsets(int index,vector<int>& nums,vector<int>& vec,vector<vector<int>>&res){
        if(index<0){
            res.push_back(vec);
            return;
        }

        numSubsets(index-1,nums,vec,res);
        vec.push_back(nums[index]);
        numSubsets(index-1,nums,vec,res);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<int> vec;
        vector<vector<int>> res;

        numSubsets(n-1,nums,vec,res);

        return res; 
    }
};
