#include <iostream>
#include <vector>


using namespace std;

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



int main(){
    Solution str;
    cout<<str.strStr("sadsadbutsad","sad")<<endl;
    return 0;
}