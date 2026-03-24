class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>mL(n,0);
        vector<int>mR(n,0);
        int left = 0;
        int right = 0;

        for(int i=0;i<n;i++){
            if(left<=height[i]){
                left = height[i];
            }
            mL[i] = left;
        }

        for(int i=n-1;i>=0;i--){
            if(right<=height[i]){
                right = height[i];
            }
            mR[i] = right;
        }

        int count = 0;
        for(int i=0;i<n;i++){
            int least = min(mL[i],mR[i]);
            int water = least - height[i];
            if(water>=0){
                count+=water;
            }
        }

        return count;
    }
};