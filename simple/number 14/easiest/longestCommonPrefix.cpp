//取第一个元素，假设他为最大公共前缀，做嵌套遍历
//每次只需匹配一个字符，直到不匹配为止
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string& s0 = strs[0];
        for (int j = 0; j < s0.size(); j++) {
            for (auto& s : strs) {
                if (s[j] != s0[j] || j == s.size())//如果不匹配或者s的长度小于s0的长度
                    return s.substr(0, j);
            }
        }
        return s0;//若全部匹配，且s0的长度小于其他字符串的长度，那么s0就是最长公共前缀
    }
};