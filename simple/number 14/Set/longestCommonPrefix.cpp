//set自动去重且按字典序自动排序，所以最长公共前缀一定是第一个和最后一个字符串的最长公共前缀
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        set<string> s;
        for(int i=0;i<strs.size();i++){
            s.insert(strs[i]);
        }
        string First_S=*(s.begin());;
        string Second_S;
        if(s.size()>=2){
            Second_S=*(--s.end());
        }
        else return First_S;
        int j=1;
        for(j=1;j<=(First_S.size()>Second_S.size()?First_S.size():Second_S.size());j++){
            if(First_S.substr(0,j)!=Second_S.substr(0,j)){
                goto end;
            }
        }
        end:
            return First_S.substr(0,j-1);
    }
};