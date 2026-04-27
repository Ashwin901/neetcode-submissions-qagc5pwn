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

        for(int i = 0;i<n2-n1+1;i++){
            if(freq.find(s2[i]) != freq.end()){
                unordered_map<char, int> temp = freq;
                int found = 1;
                for(int j = i;j<i+n1;j++){
                    if(temp[s2[j]] > 0){
                        temp[s2[j]]--;
                    } else {
                        found =0;
                        break;
                    }
                }
                if (found) return true;
            }
        }

        return false;
    }
};