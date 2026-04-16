class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        unordered_map<string, int> umap;
        int n = words.size();
        for(int i =0;i<n;i++ ){
            umap[words[i]] = 1;
        }

        if(umap.find(endWord) == umap.end()) return 0;

        // bfs
        queue<string> q;

        q.push(beginWord);
        int res = 0;
        unordered_map<string, int> visited;
        while(!q.empty()){
            int size = q.size();
            res++;
            while(size--){
                string curr = q.front(); q.pop();
                if(curr == endWord) return res;
                visited[curr] = 1;
                for(int i = 0;i<curr.length();i++){
                    string word = curr;
                    for(int j = 0;j<26;j++){
                        char c = 'a' + j;
                        if(c == curr[i]) continue;
                        word[i] = c;
                        if(umap.find(word) != umap.end() && visited.find(word) == visited.end()) q.push(word);
                    }
                }
            }
        }

        return 0;
    }
};
