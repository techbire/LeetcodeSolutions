class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>x;
        for(char c:s){
            if(!x.empty()&&x.top()=='('&&c==')')
                x.pop();
            else x.push(c);
        }
        return x.size();
    }
};