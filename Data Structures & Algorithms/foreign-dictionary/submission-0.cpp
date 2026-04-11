class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int m = words.size();

        unordered_map<char, int> nIEdges;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<words[i].length();j++){
                nIEdges[words[i][j]] = 0;
            }
        }
        unordered_set<string> edges; // just to keep track of already included edges
        unordered_map<char, vector<char>> aList;

        for(int i = 0;i<m-1;i++){
            int j = i + 1;
            int l1 = words[i].length(), l2 = words[j].length();
            int i1 = 0, i2 = 0;
            string s1 = words[i], s2 = words[j];
            bool found = false;
            while(i1 < l1 && i2 < l2){
                if(s1[i1] != s2[i2]){
                    string s = string(1, s1[i1]) + s2[i2];
                    if(edges.find(s) == edges.end()) {
                        nIEdges[s2[i2]]++;
                        aList[s1[i1]].push_back(s2[i2]);
                        edges.insert(s);
                    }
                    found = true;
                    break;
                }
                i1++;i2++;
            }
            if (!found && l1 > l2) return "";
        }

        queue<char> q;
        for(auto it : nIEdges){
            if(it.second == 0){
                q.push(it.first);
            }
        }

        string res = "";

        while(!q.empty()){
            char curr = q.front();
            q.pop();

            res += curr;

            for(int i = 0;i<aList[curr].size();i++){
                char d = aList[curr][i];
                nIEdges[d]--;
                if(nIEdges[d] == 0) q.push(d);
            }
        }

        if(res.length() != nIEdges.size()) return "";
        return res;
        
    }
};