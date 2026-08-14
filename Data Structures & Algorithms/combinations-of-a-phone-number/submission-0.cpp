class Solution {
public:
    vector<string> ans;
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
    void dfs(int index,string& digits,string& current){
        if(index==digits.length()){
            ans.push_back(current);
            return;
        }
        char digit=digits[index]-'0';
        for(char ch:mpp[digit]){
            current.push_back(ch);
            dfs(index+1,digits,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string current;

        if(digits.size()==0) return {};

        dfs(0,digits,current);

        return ans;
        
    }
};