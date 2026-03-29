//双指针比较，文本指针绝不会退，模式指针在不匹配时回退到next数组中记录的位置，继续比较，直到找到匹配的字符串或者文本指针遍历完。
vector<int> get_next(const string& needle);
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        int slow=0,fast=0;
        vector<int> next=get_next(needle);
        while(fast<m){
            if(haystack[fast]==needle[slow]){
                slow++;
                fast++;
            }
            if(slow==n) return fast-n;
            else if(fast<m&&haystack[fast]!=needle[slow]){
                if(slow!=0) slow=next[slow-1];
                else{
                    fast++;
                }
            }
        }
        return -1;
    }
};
//找到最大公共前后缀，存入数组中，当不匹配时，slow回退到next[slow-1]的位置，继续比较，直到找到匹配的字符串或者haystack遍历完。
vector<int> get_next(const string& needle){
    int m=needle.size();
    int slow=0,fast=1;
    vector<int> next(m,0);
    while(fast<m){
        if(needle[fast]==needle[slow]){
            slow++;
            next[fast]=slow;
            fast++;
        }else{
            if(slow!=0) slow=next[slow-1];
            else{
                next[fast]=0;
                fast++;
            }
        }
    }
    return next;
}