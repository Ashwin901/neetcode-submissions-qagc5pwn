class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if(n == 1) return {0};

        vector<int> nIEdges(n,0);
        unordered_map<int, vector<int>> aList;

        int m = pre.size();

        for(int i = 0;i<m;i++){
            int s = pre[i][1];
            int d = pre[i][0];

            nIEdges[d]++;
            aList[s].push_back(d);
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(nIEdges[i] == 0){
                q.push(i);
            }
        }

        if(q.empty()) return {};

        vector<int> res;

        while(!q.empty()){
            int s = q.front();
            q.pop();

            res.push_back(s);
            for(int i = 0;i<aList[s].size();i++){
                int d = aList[s][i];
                nIEdges[d]--;
                if(!nIEdges[d]) q.push(d);
            }
        }


        if(res.size() == n) return res;
        return {};
    }
};
