class Solution {
public:
    //Approach: Prefix Sum with Parity Counting

    //Time Complexity = O(n) =>
    /* Traverse the array once.
    * Each iteration performs constant-time operations: update parity, add a count, and increment a counter.
    * Therefore, total time is O(n).
    */

    //Space Complexity = O(1) =>
    /* Used only a fixed number of variables: MOD, even, odd, parity, and answer.
    * No extra array or data structure grows with the input.
    * Therefore, auxiliary space is O(1)
    */

    int numOfSubarrays(vector<int>& arr) {
        
        //Step 1: Initialize
        const int MOD = 1e9 + 7;//10^9 + 7
        int even = 1, odd = 0;
        int pairity = 0, ans = 0;

        //Step 2: Traverse the array
        for(int num : arr){

            pairity = (pairity + num) % 2;

            //Step 3: Count new valid subarrays
            if(pairity == 1){//odd pairity 
                // Current prefix is odd. Subtracting any earlier even prefix
                // gives an odd-sum subarray, so add their count.
                ans = (ans + even) % MOD;
            }

            else{ //even pairity
                // Current prefix is even. Subtracting any earlier odd prefix
                // gives an odd-sum subarray, so add their count.
                ans = (ans + odd) % MOD;
            }

            //Step 4: Record the current prefix
            if(pairity == 1){
                odd++;
            }
            else{
                even++;
            }
        }

        //Step 5: Return the answer
        return ans;       
        
    }
};