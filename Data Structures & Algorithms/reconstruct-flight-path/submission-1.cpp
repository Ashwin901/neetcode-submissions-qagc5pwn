class Solution {
public:

    bool dfs(string curr,int numberOfTickets, int ticketsUsed, 
        unordered_map<string, vector<pair<string, int>>> &aList,
        vector<int> &visited, vector<string> currentPath, vector<string> &res){

        if(ticketsUsed == numberOfTickets) {
            res.insert(res.end(),currentPath.begin(), currentPath.end());
            return true;
        }

        for(int i = 0;i<aList[curr].size();i++){
            string dest = aList[curr][i].first;
            int ticket = aList[curr][i].second;
            if(visited[ticket]) continue;
            visited[ticket] = 1;
            vector<string> temp = currentPath;
            temp.push_back(dest);
            if(dfs(dest,numberOfTickets,ticketsUsed +1,aList,visited,temp, res)) return true;
            visited[ticket] = 0;
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int m = tickets.size();
        unordered_map<string, vector<pair<string, int>>> aList;

        for(int i = 0;i<m;i++){
            vector<string> ticket = tickets[i];
            aList[ticket[0]].push_back({ticket[1],i});
        }

        for(auto& it: aList){
            sort(it.second.begin(), it.second.end());
        }
        vector<int> visited(m,0);
        vector<string> res;
        if(dfs("JFK",m,0,aList,visited,{"JFK"},res)){
            return res;
        }

        return res;
    }
};
