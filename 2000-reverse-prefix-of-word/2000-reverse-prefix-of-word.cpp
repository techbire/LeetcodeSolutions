class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pivot_index=-1;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                pivot_index=i;
                break;
            }
        }
        if(pivot_index!=-1){
            int left=0;
            int right=pivot_index;
            while(left<right){
                char temp=word[left];
                word[left]=word[right];
                word[right]=temp;
                left++;
                right--;
            }
        }
    return word;
    }
};