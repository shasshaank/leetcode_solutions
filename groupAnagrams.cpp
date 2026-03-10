class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>map;
        for(int i=0;i<strs.size();i++){
            string sortedString  = strs[i];
            sort(sortedString.begin(),sortedString.end());
            map[sortedString].push_back(strs[i]);
        }
        vector<vector<string>>result;
        for(auto &pair:map){
            result.push_back(pair.second);
        }

        return result;
    }
};