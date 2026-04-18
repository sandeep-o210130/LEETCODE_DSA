class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        vector<double> ang;
        int a = sides[0],b=sides[1],c=sides[2];
        if((sides[0]+sides[1])<=sides[2]) return ang;
        double a1 = (double)((c*c)+(b*b)-(a*a))/(double)(2*b*c);
        double b1 = (double)((c*c)+(a*a)-(b*b))/(double)(2*a*c);
        double c1 = (double)((a*a)+(b*b)-(c*c))/(double)(2*a*b);
        
        ang.push_back(acos(a1)*(180.0)/(M_PI));
        ang.push_back(acos(b1)*(180.0)/(M_PI));
        ang.push_back(acos(c1)*(180.0)/(M_PI));
        sort(ang.begin(),ang.end());
        return ang;
    }
};