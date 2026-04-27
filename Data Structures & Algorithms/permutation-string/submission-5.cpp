class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n2 < n1) return false;

        unordered_map<char, int> freq;

        for(int i = 0;i<n1;i++){
            freq[s1[i]]++;
        }

        int i = 0,j = 0;
        int count = 0;
        unordered_map<char, int> freq2;
        while(j < n2){
            // curr char doesn't exist in s1
            if(freq.find(s2[j]) == freq.end()){
                count = 0; // we reset the count, all the matching characters so far are useless now
                while(i < j){
                    freq2[s2[i]]--;
                    i++;
                }
                j++;
                i = j;
                continue;
            }

            // basically if the current char was already matching then we will need to remove that
            while(freq[s2[j]] == freq2[s2[j]]){
                count--;
                freq2[s2[i]]--;
                i++;
            }

            freq2[s2[j]] += 1;
            count++;

            if(count == n1) return true;
            j++;
        }

        return false;
    }
};