class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        vector<int>state;
        vector<bool>selected(n,false);
        backtrack(state,nums,selected,res);
        return res;
    }

    void backtrack(vector<int>&state, vector<int>&choices, vector<bool>&selected,vector<vector<int>>&res){
        if(state.size()==choices.size()){
            res.push_back(state);
            return;
        }

        for(int i=0;i<choices.size();i++){
            if(!selected[i]){
                selected[i] = true;
                state.push_back(choices[i]);
                backtrack(state,choices,selected,res);
                selected[i] = false;
                state.pop_back();

            }
        }
    }
};