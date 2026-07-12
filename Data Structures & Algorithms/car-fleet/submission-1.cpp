class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> vec;

        for(int i=0;i<position.size();i++){
            double time=(double)(target-position[i])/speed[i];
            vec.push_back({position[i],time});
        }

        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        int fleet=0;
        double current_time=0;
        for(auto car:vec){
            if(current_time<car.second){
                fleet++;
                current_time=car.second;
            }
        }
        return fleet;
    }
};
