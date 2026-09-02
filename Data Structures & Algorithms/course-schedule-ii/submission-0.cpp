class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]+=1;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]-=1;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};
