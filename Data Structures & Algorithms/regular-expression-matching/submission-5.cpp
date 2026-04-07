class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();
        return dfs(0,0,l1,l2,s,p);
    }

    bool dfs(int i, int j, int l1, int l2, string s, string p){
        if(j == l2) return i == l1;

        // skip if j + 1 = '*'
        if(j + 1 < l2 && p[j+1] == '*'){
          if(dfs(i,j+2,l1,l2,s,p)) return true;  
        }

        // match
        if(i < l1 && (p[j] == '.' || s[i] == p[j])){
            return dfs(i+1,j+1,l1,l2,s,p);
        }

        // p[j] = '*'
        // 1. skip
        if(p[j] == '*'){
            if(dfs(i,j+1,l1,l2,s,p)) return true;
            if(i < l1 && j > 0 && (p[j-1] == '.' || p[j-1] == s[i])) return dfs(i+1,j,l1,l2,s,p);
        }
        
        return false;
    }
};
