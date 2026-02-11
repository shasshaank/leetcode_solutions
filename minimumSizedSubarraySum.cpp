class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minLength = INT_MAX;
        int currentSum = 0;
        for(int r=0;r<nums.size();r++){
            currentSum+=nums[r];

            while(currentSum>=target){
                minLength = min(minLength,r-l+1);
                currentSum-=nums[l];
                l++;
            }
        }

        return (minLength==INT_MAX)?0:minLength;
    }
};