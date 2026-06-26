class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
             unordered_map<char,int> check;
            for(int col=0;col<9;col++){
                char c=board[row][col];
                if(c=='.') continue;
                else{
                    check[c]++;
                    if(check[c]>1){
                        return false;
                    }
                }
            }
        }
        for(int col=0;col<9;col++){
             unordered_map<char,int> check;
            for(int row=0;row<9;row++){
                char c=board[row][col];
                if(c=='.') continue;
                else{
                    check[c]++;
                    if(check[c]>1){
                        return false;
                    }
                }
            }
        }
        for(int subRow=0;subRow<3;subRow++){
        for(int subCol=0;subCol<3;subCol++){
            unordered_map<char,int> check;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    char c=board[subRow*3+i][subCol*3+j];
                    if(c=='.') continue;
                    else{
                        check[c]++;
                        if(check[c]>1){
                            return false;
                        }
                    }
                    
                }
            }
            }
        }
        return true;
    }
};
