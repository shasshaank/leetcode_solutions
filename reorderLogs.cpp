class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>lets;
        vector<string>digs;
        for(const string& log:logs){
            int spaceIdx = log.find(' ');
            if(isdigit(log[spaceIdx+1])){
                digs.push_back(log);
            }else{
                lets.push_back(log);
            }
        }
        auto comp = [](const string &a, const string &b){
            int spaceA = a.find(' ');
            int spaceB = b.find(' ');

            string_view ContentA = string_view(a).substr(spaceA+1);
            string_view ContentB = string_view(b).substr(spaceB+1);
            if(ContentA != ContentB){
                return ContentA < ContentB;
            }

            return a<b;
        };

        sort(lets.begin(),lets.end(),comp);
        lets.insert(lets.end(),digs.begin(),digs.end());
        return lets;
    }
};