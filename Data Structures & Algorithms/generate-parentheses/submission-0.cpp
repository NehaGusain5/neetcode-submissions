class Solution {
public:
    void recurParenthesis(string& current,int open,int close,int n,vector<string>& ans){
        if(close==n){
            ans.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            recurParenthesis(current,open+1,close,n,ans);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            recurParenthesis(current,open,close+1,n,ans);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        recurParenthesis(current,0,0,n,ans);
        return ans;
    }
};
