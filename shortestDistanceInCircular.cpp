class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;
        bool found = false;
        for(int i= 0;i<n;i++){
            if(words[i]==target){
                found = true;
                int linearDistance = abs(i-startIndex);
                int circularDistance = n - linearDistance;
                int actualDistance = min(linearDistance,circularDistance);
                minDistance = min(minDistance,actualDistance);
            }
        }

        return found? minDistance : -1;
    }
};