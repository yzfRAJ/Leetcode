//string，比较单个字符用' '，注意区分
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=s.size()-1;
        int substr_length=0;
        while(length>=0){
            if(s[length]!=' '){
                substr_length++;
                if(length==0||s[length-1]==' '){
                    return substr_length;
                }
            }
            length--;
        }
        return substr_length;
  