class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, int> dict;

        for(int i = 0;i<wordDict.size();i++){
            dict[wordDict[i]] = 1;
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);

        while(!q.empty()){
            int start = q.front(); q.pop();
            if (visited[start]) continue;
            visited[start] = true;
            string sub = "";
            for(int i = start;i<n;i++){
                sub += s[i];
                if(dict.find(sub) != dict.end()){
                    if(i == n-1) return true;
                    q.push(i+1);
                }
            }
        }

        return false;
    }
};
