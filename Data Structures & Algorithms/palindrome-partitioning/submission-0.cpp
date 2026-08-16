class Solution {
public:
    bool isPalin(string &s, int left, int right) {
        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
    void dfs(vector<string>& current,vector<vector<string>>& ans,int index,string& s){
        if(index==s.length()){
            ans.push_back(current);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                current.push_back(
                    s.substr(index, i - index + 1)
                );
                dfs(current,ans,i+1,s);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        dfs(current,ans,0,s);

        return ans;
    }
};