//思路，首先判断字符串长度是否为奇数，如果是则直接返回false；
//然后从字符串末尾开始遍历，遇到左括号就判断它后面一个字符是否是对应的右括号，如果是则删除这两个字符，否则返回false；
//一定要从末尾开始遍历，因为如果从前面开始遍历的话，可能会出现删除了一个括号之后，后面的括号就不对应了的情况；
//从末尾开始遍历只需要判断遇到的左括号的后面一个字符是否是对应的右括号，因为从末尾开始遍历，遇到的左括号必定是第一个左括号
class Solution {
public:
    bool isValid(string s) {
        char str[7] = {'(', ')', '{', '}', '[', ']'};
        int original = s.size();
        if (s.size() % 2 == 1)
            return false;
        for (int i = original - 1; i >= 0; i--) {//从末尾开始遍历
            for (int j = 0; j < 6; j += 2) {
                if (s[i] == str[j]) {
                    if (s[i + 1] == str[j + 1]) {
                        s.erase(i, 2);
                        break;
                    } else
                        return false;
                }
            }
        }
        return s.size() == 0 ? true : false;
    }
};