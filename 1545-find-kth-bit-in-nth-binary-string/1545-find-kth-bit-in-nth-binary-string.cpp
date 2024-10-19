class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string bits = "0";
        for(int i = 1; i < n; i++)
        {
            string Bits = "1";
            int size = bits.size();
            for(int i = size - 1; i >= 0; i--)
                Bits += (bits[i] == '0' ? '1' : '0');
            bits += Bits;
        }
        return bits[k - 1];
    }
};