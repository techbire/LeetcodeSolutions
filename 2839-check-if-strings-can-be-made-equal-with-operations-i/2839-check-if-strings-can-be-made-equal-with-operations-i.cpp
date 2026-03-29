class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Swap (0, 2) if match s2
        if (s1[0] != s2[0]) swap(s1[0], s1[2]);
        
        // Swap (1, 3) if match s2
        if (s1[1] != s2[1]) swap(s1[1], s1[3]);
    
        // After potential match
        return s1 == s2;
    }
};