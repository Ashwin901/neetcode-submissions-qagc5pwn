class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key) == umap.end()) return "";
        vector<pair<string,int>> nums = umap[key];
        
        int l = 0, r = nums.size() -1;
        int res = -1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m].second == timestamp){
                return nums[m].first;
            }

            if(nums[m].second > timestamp){
                r = m-1;
            } else {
                res = m;
                l = m+1;
            }
        }

        if(res == -1) return "";
        return nums[res].first;
    }
};
