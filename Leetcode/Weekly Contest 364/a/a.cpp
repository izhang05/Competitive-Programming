class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero = 0, one = 0;
        string res;
        for (auto &i: s) {
            if (i == '0') {
                ++zero;
            } else {
                ++one;
            }
        }
        for (int i = 0; i < one - 1; ++i) {
            res += "1";
        }
        for (int i = 0; i < zero; ++i) {
            res += "0";
        }
        res += "1";
        return res;
    }
};