class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>store;
    string find(vector<pair<int,string>>&values,int timestamp){
        int l = 0;
        int r = values.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(values[mid].first<=timestamp){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        if(r<0){
            return "";
        }
        return values[r].second;
    }
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()){
            return "";
        }

        auto & values = store[key];
        string result = find(values,timestamp);
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */