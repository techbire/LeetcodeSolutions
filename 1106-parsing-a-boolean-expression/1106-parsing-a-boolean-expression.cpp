class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char ch:expression){
            if(ch==','|ch=='('){
                continue;
            }
            if(ch=='t'||ch=='f'||ch=='!'||ch=='&'||ch=='|'){
                st.push(ch);
            } 
            else if(ch==')'){
                bool hasTrue=false,hasFalse=false;
                while(st.top()=='t'||st.top()=='f'){
                    hasTrue|=st.top()=='t';
                    hasFalse|=st.top()=='f';
                    st.pop();
                }
                char op=st.top();
                st.pop();
                bool result;
                if (op=='!'){
                    result=!hasTrue;
                } 
                else if(op=='&'){
                    result=!hasFalse;
                } 
                else{
                    result=hasTrue;
                }
                st.push(result?'t':'f');
            }
        }
        return st.top() == 't';
    }
};