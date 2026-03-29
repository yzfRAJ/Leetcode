class Solution {
public
    int strStr(string haystack, string needle) {
        int needle_length=needle.size();
        int hay_length=haystack.size();
        for(int j=0;jhay_length;j++){
            if(haystack[j]==needle[0]){
                if(haystack.substr(j,needle_length)==needle)
                    return j;
            }
        }
        return -1;
    }
};