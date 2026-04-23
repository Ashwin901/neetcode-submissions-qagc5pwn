class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int beg = 1;
        int end = *max_element(piles.begin(), piles.end());

        if(n == h) return end;
        if(n > h) return -1;
        int res = end;
        while(beg <= end){
            int mid = beg + ((end-beg)/2);

            // check if mid can be the answer
            int curr = 0;
            for(int i = 0;i<n;i++){
                curr += ceil((double)piles[i]/mid);
            }

            if(curr <= h){
                res = mid;
                end = mid -1;
            } else {
                beg = mid + 1;
            }
        }

        return res;
    }
};
