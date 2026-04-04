class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        unordered_map<string, int> umap;
        return dfs(0,m,n,l,strs,0, umap);
    }

    int dfs(int i, int m, int n, int l, vector<string> &strs, int currSize, unordered_map<string, int> &umap){
        if(i == l){ 
            return 0;
        }
        string key = to_string(i) + "," + to_string(m) + "," + to_string(n);
        if(umap.find(key) != umap.end()) return umap[key];

        int z = 0, o = 0;

        for(char c : strs[i]){
            if(c == '0') z++;
            if(c == '1') o++;
        }

        // include
        int include = 0;
        if(z <= m && o <= n){
            include = 1 + dfs(i+1,m-z,n-o,l,strs,currSize+1, umap);
        } 

        // exclude
        int exclude = dfs(i+1,m,n,l,strs,currSize, umap);

        umap[key] =  max(include, exclude);
        return umap[key];
    }
};