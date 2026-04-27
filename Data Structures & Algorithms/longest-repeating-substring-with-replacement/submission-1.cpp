class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int i = 0, j = 0;
        int maxFreq = 0;
        unordered_map<char, int> freq;
        int res = 1;
        while(j < n){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);

            int currWindowSize = j - i + 1;
            while((j-i+1) - maxFreq > k && i < j){
                freq[s[i]]--;
                i++;

                maxFreq = 0;
                for(auto it : freq){
                    maxFreq = max(maxFreq, it.second);
                }
            }

            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};
