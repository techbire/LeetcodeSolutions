//approach 
// Words ko split karenge: Dono sentences ko words mein convert karne ke liye split() function use kiya hai.
// l aur r lenge: l left se aur r right se compare karega words ko.
// Comparison start se aur end se: l words ko start se match karega aur r end se. Jab tak match hota rahega, l aur r badhte rahenge.
// Condition check: Jab left aur right ka sum smaller sentence ke size ke barabar ya usse zyada ho jaye, to sentences similar hain, return true karenge.


class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Split both sentences into words
        vector<string> w1 = split(s1), w2 = split(s2);
        
        // Ensure w1 is the shorter one
        if (w1.size() > w2.size()) swap(w1, w2);
        
        int l = 0, r = 0, n = w1.size(), m = w2.size();
        
        // Compare from the start
        while (l < n && w1[l] == w2[l]) l++;
        
        // Compare from the end
        while (r < n && w1[n - 1 - r] == w2[m - 1 - r]) r++;
        
        // Check if total matching from left and right covers w1
        return l + r >= n;
    }

private:
    vector<string> split(const string& s) {
        istringstream ss(s);
        string word;
        vector<string> res;
        while (ss >> word) res.push_back(word);
        return res;
    }
};


