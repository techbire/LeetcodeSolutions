class Solution {
public:
    int minLength(string s) {
        
        
        
        stack<char> st;

    
        for (char c : s) {
           
            if (!st.empty()) {
                if (st.top() == 'A' && c == 'B') {
                    st.pop();  
                    continue;
                }
                else if (st.top() == 'C' && c == 'D') {
                    st.pop();  
                    continue;
                }
            }
          
            st.push(c);
        }

    
        return st.size();
    }
};
        
        
        
        
