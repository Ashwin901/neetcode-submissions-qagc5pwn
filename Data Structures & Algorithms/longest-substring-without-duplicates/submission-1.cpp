class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int i = 0, j = 0;
        unordered_map<char, int> umap;
        int res = 1;
        while( j < n){
            umap[s[j]]++;
            while(umap[s[j]] > 1){
                umap[s[i]]--;
                i++;
            }

            res = max(res, j-i+1);
            j++;
        }

        return res;
    }
};
