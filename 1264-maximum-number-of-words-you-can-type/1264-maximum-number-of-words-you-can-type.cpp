class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(auto ch:brokenLetters){
            st.insert(ch);
        }
        int ans=0;
        bool broken=false;
        for(auto ch:text){
            if(ch==' '){
                if(!broken){
                    ans++;
                }
                broken=false;
            }
            else if(st.find(ch)!=st.end()){
                broken=true;
            }
        }
        if(broken==false) ans++;
        return ans;
    }
};