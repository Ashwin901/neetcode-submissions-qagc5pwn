class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        // we run k+1 times because there are k+1 edges , 2 + k(nodes in between)
        // we can assume these k+1 edges as the number of flights we can take
        // at first we can only take a flight from source
        // second step we can take a flight from all the stops that src was able to reach in the previous step
        for(int i = 0;i<=k;i++){    
            vector<int> tempPrices = prices;
            for(int j = 0;j<m;j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int p = flights[j][2];

                // this just means that we have not even reached this place, so we cannot take a flight from here
                if(prices[s] == INT_MAX) continue;

                tempPrices[d] = min(tempPrices[d], p + prices[s]);
            }

            prices = tempPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
