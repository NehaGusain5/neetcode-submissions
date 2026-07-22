class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<string,int>>> mp;
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key)==mp.end()){
            return "";
        }

        auto& result=mp[key];

        int low=0;
        int high=result.size()-1;
        string answer="";

        while(low<=high){
            int mid=low+(high-low)/2;

            if(result[mid].second<=timestamp){
                answer=result[mid].first;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return answer;
        
    }
};
