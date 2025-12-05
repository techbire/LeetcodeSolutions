class Solution {
public:
    int countCollisions(string d) {
    int n=d.size(),i=0,j=n-1,s=0; 
    while(i<n&&d[i]=='L')i++;
    while(j>=0&&d[j]=='R')j--;
    for(int k=i;k<=j;k++)if(d[k]!='S')s++;
    return s;

    }
};