class Solution {
public:
    void combSum(int index, int n, vector<vector<int>>& ans, vector<int>& vec,
                 vector<int>& nums, int target) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }

        for (int i = index; i < n; i++) {
            if (i > index && nums[i] == nums[i-1]) continue;

            if (nums[i] > target) break; 

            vec.push_back(nums[i]);
            combSum(i+1, n, ans, vec, nums, target - nums[i]);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        vector<int> vec;
        combSum(0, nums.size(), ans, vec, nums, target);
        return ans;
    }
};
