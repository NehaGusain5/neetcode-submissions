class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int longestLen=0;

        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int current=it;
                int currLen=1;
                while(st.find(current+1)!=st.end()){
                    current+=1;
                    currLen+=1;
                }
                longestLen=max(longestLen,currLen);
            }
        }
        return longestLen;
    }
};
