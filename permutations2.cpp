class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        vector<int>state;
        vector<bool>selected(n,false);
        backtrack(state,nums,selected,res);
        return res;
    }

    void backtrack(vector<int>&state,vector<int>&choices,vector<bool>&selected,vector<vector<int>>&res){
        if(state.size()==choices.size()){
            res.push_back(state);
            return;
        }

        unordered_set<int>duplicated;
        for(int i=0;i<choices.size();i++){
            int choice = choices[i];
            if(!selected[i] && duplicated.find(choice)==duplicated.end()){
                duplicated.emplace(choice);
                selected[i] = true;
                state.push_back(choice);
                backtrack(state,choices,selected,res);
                selected[i] = false;
                state.pop_back();
            }   
        }
    }
};