class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxCount = 0;
        int i = 0, res = 0;

        for (int j = 0; j < n; ++j) {
            freq[s[j] - 'A']++;
            maxCount = max(maxCount, freq[s[j] - 'A']);

            while (j - i + 1 - maxCount > k) {
                freq[s[i] - 'A']--;
                i++;
                // maxCount can stay as is; this version relies on the fact
                // that maxCount is an upper bound for the current window.
            }

            res = max(res, j - i + 1);
        }
        return res;
    }
};