class Solution {

public:

    int lefttoright(string s){
        int left = 0;
        int right = 0;
        int maxDis = 0;
        int count = 0;

        for(right = 0; right < s.size(); right++){

            if(s[right] == '('){
                count++;
            }
            else{
                count--;
            }

            if(count < 0){
                count = 0;
                left = right + 1;
            }

            if(count == 0){
                maxDis = max(maxDis, right - left + 1);
            }
        }

        return maxDis;
    }

    int righttoleft(string s){
        reverse(s.begin(), s.end());

        int left = 0;
        int right = 0;
        int maxDis = 0;
        int count = 0;

        for(right = 0; right < s.size(); right++){

            if(s[right] == ')'){
                count++;
            }
            else{
                count--;
            }

            if(count < 0){
                count = 0;
                left = right + 1;
            }

            if(count == 0){
                maxDis = max(maxDis, right - left + 1);
            }
        }

        return maxDis;
    }

    int longestValidParentheses(string s) {
        return max(righttoleft(s), lefttoright(s));
    }
};