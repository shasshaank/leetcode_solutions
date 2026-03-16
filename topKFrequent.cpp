class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>freq;
        vector<vector<int>>bucket(n+1);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        for(auto& pair: freq){
            bucket[pair.second].push_back(pair.first);
        }
        vector<int>result;
        for(int i = nums.size();i>=0 && result.size()<k;i--){
            for(int num:bucket[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }

        return result;
    }
};