class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>state;
        vector<vector<int>>res;
        backtrack(0,state,nums,res);
        return res;
    }

    void backtrack(int start, vector<int>&state,vector<int>&choices, vector<vector<int>>&res){
        res.push_back(state);
        for(int i=start;i<choices.size();i++){
            state.push_back(choices[i]);
            backtrack(i+1,state,choices,res);
            state.pop_back();
        }
    }
};