class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<list<int>> bucket(nums.size()+1);

        for(auto it:mpp){
           int num=it.first;
           int freq=it.second;
            bucket[freq].push_back(num);
            
        }
        vector<int> result;
        for(int i=bucket.size()-1;i>=0&&result.size()<k;i--){
            for(int n:bucket[i]){
                result.push_back(n);
            }
                if(result.size()==k){
                    break;
                }
            

        }
        return result;        
        
    }
};
