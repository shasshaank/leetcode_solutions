
class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }

    int atMost(vector<int>&nums,int k){
        int n = nums.size();
        int left = 0;
        int distinct = 0;
        int res = 0;
        vector<int>freq(n+1);
        for(int right=0;right<n;right++){
            int x = nums[right];
            if(freq[x]==0){
                distinct++;
            }
            freq[x]++;

            while(distinct>k){
                int y = nums[left];
                freq[y]--;
                if(freq[y]==0){
                    distinct--;
                }
                left++;
            }

            res+=(right-left)+1;
        }

        return res;
    }
};