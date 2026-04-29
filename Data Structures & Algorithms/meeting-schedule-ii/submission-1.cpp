/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> t;
        for(int i = 0;i<intervals.size();i++){
            t.push_back({intervals[i].start,1});
            t.push_back({intervals[i].end,-1});
        }
        sort(t.begin(), t.end());
        int rooms = 0;
        int res = 0;
        for(int i = 0;i<t.size();i++){
            rooms +=  t[i].second;
            res = max(res, rooms);
        }

        return res;
    }
};
