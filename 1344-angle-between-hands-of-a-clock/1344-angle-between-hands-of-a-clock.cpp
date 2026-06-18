class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 30*hour-(5.5*(minutes));
        return min(abs(ans),abs(360-abs(ans)));
    }
};