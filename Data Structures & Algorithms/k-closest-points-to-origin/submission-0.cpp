class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, int>> dist(n);

        if(n==1 && k >=1) return {points[0]};

        for(int i = 0;i<n;i++){
            dist[i].first = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            dist[i].second = i;
        }

        priority_queue<pair<int,int>> pq;

        for(int i = 0;i<n;i++){
            if(pq.size() < k){
                pq.push(dist[i]);
                continue;
            }

            pair<int, int> top = pq.top();

            if(dist[i].first < top.first){
                pq.pop();
                pq.push(dist[i]);
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            pair<int, int> top = pq.top(); pq.pop();
            res.push_back(points[top.second]);
        }

        return res;

    }
};