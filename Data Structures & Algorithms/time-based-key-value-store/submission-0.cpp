class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key))
        return "";

        auto &element = mp[key];
        int left = 0, right = element.size()-1;
        string result = "";
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(element[mid].first<=timestamp)
            {
                result = element[mid].second;
                left = mid+1;
            }
            else
            right = mid-1;
        }
        return result;
    }
};