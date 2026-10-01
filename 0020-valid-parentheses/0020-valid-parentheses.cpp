class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{') s1.push(i);
            else{
                if(s1.empty()) return false;
                char temp = s1.top();
                if(!(i==')' && temp=='(') && !(i==']' && temp=='[')
                && !(i=='}' && temp=='{')) return false;
                s1.pop();
            }
        }   
        return (s1.empty())?true:false;
    }
};