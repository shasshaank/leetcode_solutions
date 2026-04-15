class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);
        for(auto prerequisite : prerequisites){
            int preCourse = prerequisite[1];
            int course = prerequisite[0];
            adj[preCourse].push_back(course);
            inDegree[course]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int>result;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);

            for(int v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(result.size()==numCourses){
            return result;
        }else{
            return {};
        }
    }
};