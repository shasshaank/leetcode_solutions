class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjacencyList(numCourses);
        vector<int>inDegree(numCourses,0);

        for(auto prerequisite: prerequisites){
            int preCourse = prerequisite[1];
            int course = prerequisite[0];
            adjacencyList[preCourse].push_back(course);
            inDegree[course]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int courses_processed = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            courses_processed++;
            for(int v: adjacencyList[u]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }

        return courses_processed == numCourses;
    }
};