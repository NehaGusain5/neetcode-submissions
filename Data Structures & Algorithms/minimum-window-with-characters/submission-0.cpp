class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        int n=s.size();
        int left=0;
        int have=0;
        for(char ch:t){
            need[ch]++;
        }
        int needCount=need.size();
        int minLen=INT_MAX;
        int start=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            window[ch]++;
            if(need.count(ch)&&need[ch]==window[ch]){
                have++;
            }
            while(have==needCount){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }
                char st=s[left];
                window[st]--;
                if(need.count(st)&&window[st]<need[st]){
                    have--;
                }
                left++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);

    }
};
