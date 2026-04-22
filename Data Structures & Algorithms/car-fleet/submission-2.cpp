class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double,double>> cars;
        
        for(int i =0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());
        // for detailed explanation view neetcode video
        // we move from descending order because when a car meets another car with higher position
        // its speed will reduce to match the speed of the higher position car, so now both the cars
        // will reach at the time the higher position car would reach. So it's better to compare with the 
        // higher position car because it remains constant whereas the car that combines with it, it's 
        // speed will eventually change.
        // And also if a car above the current car cannot catch up to a car before it then the current car
        // also will not be able to catch up to it because it is a one lane road
        int fleet = 1; 
        double timeTakenByTheNextCar = (target - cars[0].first) /cars[0].second;
        for(int i = 1;i<n;i++){
            double timeTakenByCurrentCar = (target - cars[i].first) / cars[i].second;
            // this means that this car cannot catch up to the next car
            // and the following cars can (potentially) catch up with only this car;
            // so the number of fleet will increase
            if(timeTakenByTheNextCar < timeTakenByCurrentCar){
                timeTakenByTheNextCar = timeTakenByCurrentCar;
                fleet++;
            }
        }

        return fleet;
    }
};