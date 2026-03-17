//#include <algorithm> 中的sort实现字典序排序
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string First_S=*strs.begin();
        string Final_S=*(--strs.end());
        int i=0;
        while(i<First_S.size()&&i<Final_S.size()){
            if(First_S[i]!=Final_S[i]) break;
            i++;
        }
        return First_S.substr(0,i);
    }
};