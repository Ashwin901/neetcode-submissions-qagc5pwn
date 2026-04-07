class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length();
        int l2 = p.length();

        return dfs(0,0,l1,l2,s,p);
    }

    bool dfs(int i, int j, int l1, int l2, string s, string p){
        if(i == l1 && j >= l2) return true;
        if(j >= l2) return false;
        
        bool skip = false, match = false;
        if(j < l2-1 && p[j+1] == '*'){
            skip = dfs(i,j+2,l1,l2,s,p);
        }

        if(i < l1 && (s[i] == p[j] || p[j] == '.')) match = dfs(i+1,j+1,l1,l2,s,p);
        if(p[j] == '*'){
            bool p1 = dfs(i,j+1,l1,l2,s,p);
            if(p1) return true;
            bool p2 = false;
            if(i < l1 && (j > 0 && (p[j-1] == '.' || s[i] == p[j-1]))){
                p2 =  dfs(i+1,j,l1,l2,s,p);
            }

            return p1 || p2;
        }
        

        return skip || match;
    }
};
