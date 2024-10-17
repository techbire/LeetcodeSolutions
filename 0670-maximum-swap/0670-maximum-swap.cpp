class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        vector<int> last(10, -1);
        for (int i = 0; i < numStr.size(); i++) last[numStr[i] - '0'] = i;
        for (int i = 0; i < numStr.size(); i++) {
            for (int d = 9; d > numStr[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
