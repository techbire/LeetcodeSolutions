class Solution {
    private:
    string changeVowels(string el){
        string ans = "";
        map<char, int> m({{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}});
        for(auto ch : el){
            if(m.count(ch)>0)ans+='*';
            else ans+=ch;
        }
        return ans;
    }
    string toLowerCase(string s){
        for(int i = 0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') s[i] = tolower(s[i]);
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        set<string> original (wordlist.begin(), wordlist.end());
        map<string, string> caseMap;
        map<string, string> vowelMap;

        for(auto el: wordlist){
            string lc = toLowerCase(el);
            if(caseMap.count(lc)==0) caseMap[lc]=el;
            string cw = changeVowels(toLowerCase(el));
            if(vowelMap.count(cw)==0) vowelMap[cw]=el;
        }

        vector<string> ans;
        for(string word: queries){
            if(original.count(word)) ans.push_back(word);
            else {
                string lc = toLowerCase(word);
                string cw = changeVowels(toLowerCase(word));
                if(caseMap.count(lc)) ans.push_back(caseMap[lc]);
                else if(vowelMap.count(cw)) ans.push_back(vowelMap[cw]);
                else ans.push_back("");
            }
        }
        return ans; 
    }
};