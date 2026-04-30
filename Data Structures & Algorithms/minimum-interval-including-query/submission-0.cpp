class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       sort(intervals.begin(), intervals.end());
       vector<pair<int, int>> q;
       for(int i = 0;i<queries.size();i++){
        q.push_back({queries[i],i});
       }
       sort(q.begin(), q.end());
       std::priority_queue<std::pair<int, int>, 
                    std::vector<std::pair<int, int>>, 
                    std::greater<std::pair<int, int>>> minHeap;
       int curr = 0; // no need to revisit the already added interval
       vector<int> res(q.size(), -1);
       for(int i = 0;i<q.size();i++){
            // check all the applicable intervals for this query
            while(curr < intervals.size()){
                if(q[i].first < intervals[curr][0]){
                    break; // this query starts before this interval and all the subsequent ones so  these intervals shouldn't be considered
                }
                //basically if the q is greater than the end then this interval shouldn't be considered for all the future queries as well
                // because all the future q is greater than the current q, so we only add the intervals where end is greater than q
                if(q[i].first <= intervals[curr][1]){
                    minHeap.push({intervals[curr][1] -  intervals[curr][0] + 1, intervals[curr][1]});
                }
                curr++;
            }

            // we remove all the intervals that end before q and then the interval at the top will be the answer
            while(minHeap.size() > 0 && minHeap.top().second < q[i].first){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                res[q[i].second] = minHeap.top().first;
            }
       }

       return res;
    }
};
