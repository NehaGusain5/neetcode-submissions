class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Hash(26,0);
        vector<int> s2Hash(26,0);
        sort(s1.begin(),s1.end());
        int left=0;
        int right=0;
        int s1Len=s1.size();
        int s2Len=s2.size();
        
        if(s1Len>s2Len) return false;

        while(right<s1Len){
            s1Hash[s1[right]-'a']++;
            s2Hash[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<s2Len){
            if(s2Hash==s1Hash) return true;
            right++;

            if(right!=s2Len){
                s2Hash[s2[right]-'a']++;
                s2Hash[s2[left]-'a']--;
                left++;
            }
           
        }
        return false;
    }
};
