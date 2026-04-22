class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        vector<int> res(n,0);

        stack<pair<int, int>> s;

        for(int i = 0;i<n;i++){
            while(!s.empty() && temp[i] > s.top().first){
                pair<int, int> top = s.top();
                res[top.second] = i - top.second;
                s.pop();
            }

            s.push({temp[i],i});
        }

        return res;
    }
};
