class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        for(int i=0;i<stones.size();i++) stones[i]=stones[i]%3;
        unordered_map<int,int> mpp,mpp2;
        for(auto i:stones){ mpp[i]++; mpp2[i]++; }
        bool temp=false,temp2=false;
        int size=2,i=0,sum=0;
        if(mpp[2]>0){
            while(mpp[size]>0){
                sum=(sum+size)%3;
                mpp[size]--;
                i++;
                size=((3-sum)==1)?2:1;
            }
            if(mpp[1]!=0 || mpp[2]!=0){
                i=i+mpp[0];
                temp=(i%2)?true:false;
            }
        }
        size=1,i=0,sum=0;
        if(mpp2[1]>0){
            while(mpp2[size]>0){
                sum=(sum+size)%3;
                mpp2[size]--;
                i++;
                size=((3-sum)==1)?2:1;
            }
            if(mpp2[1]!=0 || mpp2[2]!=0){
                i=i+mpp2[0];
                temp2=(i%2)?true:false;
            }
        }
        if(temp==true || temp2==true) return true;
        return false;
    }
};