class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> squares;
        for (int k = 1; k <= n; k++) {
            squares.insert(k * k);
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int sum = i * i + j * j;
                if (squares.count(sum)) {
                    count++;
                }
            }
        }
        return count;
    }
};