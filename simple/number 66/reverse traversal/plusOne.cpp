//反向遍历寻找最大9的个数，单独判断全为9的情况
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        for (int i = n; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                break;
            } else if (i != 0) {
                digits[i] = 0;
            } else {
                digits[0] = 1;
                digits.push_back(0);
            }
        }
        return digits;
    }
};