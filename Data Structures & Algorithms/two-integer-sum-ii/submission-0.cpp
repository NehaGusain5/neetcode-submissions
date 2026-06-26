class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;

        int n=numbers.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j]==target){
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                }
            }
        }
        return answer;
    }
};
