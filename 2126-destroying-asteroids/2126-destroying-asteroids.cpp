class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long masss=mass;
        for(int i=0;i<asteroids.size();i++){
            if(masss>=asteroids[i]){
                masss = masss+asteroids[i];
            }
            else return false;
        }
        return true;
    }
};