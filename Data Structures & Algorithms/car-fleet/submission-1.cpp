class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double, int>> cars(n);

        for(int i = 0;i<n;i++){
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end());

        int res = 1;
        pair<int, int> carAhead = cars[n-1];
        for(int i = n-2;i>=0;i--){
            pair<int, int> car = cars[i];
            if(car.second <= carAhead.second){
                // it can never catch up
                carAhead = car;
                res++;
                continue;
            }

            double d = carAhead.first - car.first; // dist diff
            int s = car.second - carAhead.second; // speed diff
            double intersection = (double) car.first + (car.second * (d / s));

            if(intersection > (double)target){
                carAhead = car;
                res++;
            }
        }

        return res;
    }
};
