class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for(auto &pair:freq){
            buckets[pair.second].push_back(pair.first);
        }
        vector<int>result;
        for(int i=nums.size();i>=0 && result.size()<k;i--){
            for(int num: buckets[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }

        return result;
    }
};