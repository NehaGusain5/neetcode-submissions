class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for(int i=0;i<strs.size();i++){
            int s=strs[i].size();
            result+=to_string(s)+"#"+strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        if(s.empty()) return result;
       
       while(i<s.size())
        {
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
           
            string str=s.substr(j+1,len);
            result.push_back(str);  

            i=j+1+len;
        }
       
        return result;

    }
};
