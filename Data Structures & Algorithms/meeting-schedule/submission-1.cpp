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
    static bool compare(Interval a, Interval b)
    {
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(!intervals.size())
        return true;
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i].end>intervals[i+1].start)
            return false;
        }
        return true;
    }
};
