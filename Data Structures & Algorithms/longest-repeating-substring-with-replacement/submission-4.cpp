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

            // if maxCount doesn't increase the window size will always default to the last window size it worked
            // the only way window can increase (better than the previous result) is if maxCount increases, because once the condition fails
            // and if oy window is increasing then obviously the diff will always be greater than k
            while (j - i + 1 - maxCount > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            res = max(res, j - i + 1);
        }
        return res;
    }
};