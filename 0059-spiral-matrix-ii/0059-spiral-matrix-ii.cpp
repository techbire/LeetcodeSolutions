class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> >arr(n,vector<int> (n)); 
        // int m=matrix.size(); //rows 
        // int n=matrix[0].size(); //columns
        int minr=0,maxr=n-1;
        int minc=0,maxc=n-1;
        int count=1;
        while(minr<=maxr && minc<=maxc){
            // printing the minimum row
            for(int j=minc;j<=maxc;j++){
                arr[minr][j]=count++;
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            // printing the maximum column
            for(int i=minr;i<=maxr;i++){
                arr[i][maxc]=count++;
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            // priting the maximum row
            for(int j=maxc;j>=minc;j--){
                arr[maxr][j]=count++;
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            // printing the minimum column
            for(int i=maxr;i>=minr;i--){
                arr[i][minc]=count++;
            }
            minc++;
        }
        return arr;
    }
};