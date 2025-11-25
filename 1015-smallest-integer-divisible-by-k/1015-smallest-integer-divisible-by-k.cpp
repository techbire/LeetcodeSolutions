class Solution {
public:
    int smallestRepunitDivByK(int k) {
    int m=1;
    if(k%2==0||k%5==0)return -1;
    for(int i =1;i<=k;i++){
        if(m%k==0)return i;
        m=(m%k)*10+1;
    }    
    return -1;
    }
};