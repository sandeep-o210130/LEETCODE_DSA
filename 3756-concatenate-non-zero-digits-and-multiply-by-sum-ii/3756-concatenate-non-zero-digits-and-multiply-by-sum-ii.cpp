class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        long long mod=1e9+7;

        int n = s.size();
        //i precomputed the powers to help me in further extraction of the desired number from its prefix. i didnt use pow() function because its slow.
        vector<long long> power(n + 1);
        power[0] = 1;
        for (int i=1;i<=n;i++) {
        power[i] = (power[i-1]*10) % mod;
        }


        //precomputed the numbers and their sums for each index.
        vector<long long>prefix;
        vector<pair<long long,int>>Numbers;
        long long sum=0;
        long long num=0;
        int count=0;
        for( int i=0;i<s.size();i++)
        {
            if(s[i] !='0')
            {
                num=((1LL*num*10)%mod+(s[i]-'0'))%mod;
                count++;
            }
            sum+=(s[i]-'0')%mod;
            prefix.push_back(sum);
            Numbers.push_back({num,count});
        }
        for( int i=0; i<queries.size();i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int finalNum;
            int requiredSum=0;
            //if the number doesnt start from the very first index , it means it would require some cutting from its front.


            if( start > 0 )
            {
                // this length is computed by the idea-- what was required length and what was its actual length since it takes all the number from the start.
               int len =  Numbers[end].second - Numbers[start-1].second;
               long long toMinus = (1LL * Numbers[start - 1].first * power[len]) % mod;
               finalNum = (Numbers[end].first - toMinus + mod ) % mod;  

                int totalSum= prefix[end];
                requiredSum = prefix[end] - prefix[start-1]; 
            }
            else
            {
                finalNum=Numbers[end].first;
                requiredSum= prefix[end];
            }
            int val = (1LL*finalNum*requiredSum)%mod;
            ans.push_back( val);
        }
        return ans;
        
    }
};