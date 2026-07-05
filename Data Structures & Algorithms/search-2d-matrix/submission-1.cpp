class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int high=col-1;
        while(low<row&&high>=0){
            if(matrix[low][high]==target){
                return true;
            }
            else if(matrix[low][high]<target){
                low++;
            }
            else{
                high--;
            }
        }
        return false;
    }
};
