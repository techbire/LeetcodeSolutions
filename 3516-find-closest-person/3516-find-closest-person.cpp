class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a;
        int b;
        a = x - z;
        b = y - z;
        int c = abs(a);
        int d = abs(b);
        if(c > d){
            return 2;
        }
        else if(c < d){
            return 1;
        }
        else if(c == d){
            return 0;
        }
        else{
            return 0;
        }
    }
};