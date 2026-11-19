class Solution {
public:
    int reverse(int x) {
        int org = x;
        x = abs(x);
        string strX = to_string(x);
        std::reverse(strX.begin(), strX.end());
        long long res = stoll(strX);
        if (org < 0) {
            res *= -1;
        }
        if (res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return static_cast<int>(res);
    }
};