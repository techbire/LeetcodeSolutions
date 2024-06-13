class Solution {
public:
    bool isPalindrome(int num) {
        if(num < 0)
            return false;
        else
        {
            int reversedNum = 0, originalNum, digit;
            originalNum = num;
            while(num > 0)
            {   digit = num % 10;
                num = num / 10;
                reversedNum = reversedNum * 10 + digit;
                if(reversedNum > INT_MAX / 10)
                    break;
            }
            if(reversedNum == originalNum)
                return true;
            else
                return false;}}
};
