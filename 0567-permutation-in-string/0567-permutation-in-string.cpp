class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      
        int m=s1.size();
        int n=s2.size();
        vector<int> arr(26,0),b(26,0);  //Frequency Arrays
        
        
// b: A frequency count array for the characters in s1.
// arr: A frequency count array for the first m characters of s2.
        
        if(n<m) return false;
        for(int i=0;i<m;i++){  //checking
            b[s1[i]-'a']++;
            arr[s2[i]-'a']++;
        }
      for(int i=m;i<n;i++){
            if(arr==b)return true;
            arr[s2[i]-'a']++;
            arr[s2[i-m]-'a']--;
        }
        if(arr==b)return true;
        return false;
        
        
        
    }
};
               
