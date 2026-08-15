class Solution {
public:
    vector<string> mpp={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void solve(int index,string& s,vector<string>& ans,string digits){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }

        int digit=digits[index]-'0';

        for(char ch:mpp[digit]){
            s.push_back(ch);
            solve(index+1,s,ans,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.size()==0) return {};
        string s;

        solve(0,s,ans,digits);

        return ans;
        
    }
};
