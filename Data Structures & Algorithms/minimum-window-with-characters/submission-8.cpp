class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length(), n2 = t.length();

        if(n2 > n1) return "";

        unordered_map<char, int> freq1;
        for(int i = 0;i<n2;i++){
            freq1[t[i]]++;
        }

        int i = 0, j = 0;
        int count = 0;
        int n = freq1.size();
        unordered_map<char, int> freq2;
        int res = n1+1, start = -1;
        while(j < n1){
            freq2[s[j]]++;

            if(freq1.find(s[j]) != freq1.end() && freq2[s[j]] == freq1[s[j]]) count++;
            
            if(count == n){
                while(count == n && i<=j){
                    if(freq1.find(s[i]) != freq1.end() && freq2[s[i]] == freq1[s[i]]) count--;
                    freq2[s[i]]--;
                    i++;
                } 

                if(j - (i-1) +1 < res){
                    res = j - (i-1) + 1;
                    start = i-1;
                }
            }


            j++;
        }

        if(start == -1) return "";
        return s.substr(start, res);
    }
};
