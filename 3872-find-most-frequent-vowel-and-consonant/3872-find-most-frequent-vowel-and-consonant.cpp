class Solution {
public:
    bool isVowel(char a){
        vector<char> vowels = {'a','e','i','o','u'};
        for(auto v : vowels){
            if(v == a) return true;
        }return false;
    }
    int maxFreqSum(string s) {
        unordered_map<char,int> counter;
        for(auto c : s) counter[c]++;
        int vowelMax = 0, consonantMax = 0;
        for(auto pair : counter){
            if(isVowel(pair.first)){
                if(pair.second > vowelMax) vowelMax = pair.second;
            }else{
                if(pair.second > consonantMax) consonantMax = pair.second;
            }
        }return vowelMax + consonantMax;
    }
};