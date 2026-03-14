class Solution {
public:
    string getHappyString(int n, int k) {
        string ans="";
        vector<char> alp = {'a','b','c'};
        char prev;
        for(int i=0;i<3;i++){
            if((int) pow(2,n-1)<k) k = k- (int) pow(2,n-1);
            else{
                ans+=alp[i];
                prev = alp[i];
                break;
            }
        }
        if(ans=="") return ans;
        for(int i=2;i<n;i++){
            for(int j=1;j<=2;j++){
                if((int) pow(2,n-i)<k){
                    k=k- (int) pow(2,n-i);
                }
                else{
                    if(j==1){
                        prev = ((prev=='a')?'b':'a');
                        ans = ans+""+prev;
                    }
                    if(j==2){
                        prev = ((prev=='c')?'b':'c');
                        ans = ans+ ""+prev;
                    }
                    break;
                }
            }
        }
        if(n!=1){
            if(k==1){
                    prev = ((prev=='a')?'b':'a');
                    ans = ans+""+prev;
            }
            if(k==2){
                    prev = ((prev=='c')?'b':'c');
                    ans = ans+ ""+prev;
            }
        }
        return ans;
    }
};