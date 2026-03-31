class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n==0){
            return 0;
        }
        vector<pair<int,int>> cars(n);
        for(int i=0;i<n;i++){
            cars[i] = {position[i],speed[i]};
        }

        sort(cars.begin(),cars.end(),[](const pair<int,int>&a, const pair<int,int>&b){
            return a.first>b.first;
        });

        int fleetCount = 0;
        double lastTime = -1.0;
        for(int i=0;i<n;i++){
            double currTime = (double)(target-cars[i].first)/cars[i].second;
            if(currTime>lastTime){
                fleetCount++;
                lastTime = currTime;
            }
        }

        return fleetCount;
    }
};