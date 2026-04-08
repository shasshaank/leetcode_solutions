class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums,target,0,0);
    }

    int backtrack(vector<int>&nums,int target, int index, int currentSum){
        if(index==nums.size()){
            return currentSum == target?1:0;
        }

        int add = backtrack(nums,target,index+1,currentSum + nums[index]);
        int subtract = backtrack(nums,target,index+1,currentSum - nums[index]);

        return add + subtract;

    }
};