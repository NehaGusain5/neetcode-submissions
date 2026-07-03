class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int n=s.size();
        int maxLen=0;
        int maxFreq=0;
        unordered_map<char,int> mpp(26);
        while(right<n){
            mpp[s[right]-'A']++;
            maxFreq=max(maxFreq,mpp[s[right]-'A']);
            while((right-left+1)-maxFreq>k){
                mpp[s[left]-'A']--;
                for(int i=0;i<25;i++){
                    maxFreq=max(maxFreq,mpp[i]);
                }
                left++;
            }
            if((right-left+1)-maxFreq<=k){
                maxLen=max(maxLen,(right-left+1));
                right++;
            }
        }
        return maxLen;
        
        
    }
};
