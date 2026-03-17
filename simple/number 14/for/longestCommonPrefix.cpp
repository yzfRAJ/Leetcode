class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//使用引用（&）则直接操作原始对象，没有拷贝开销
        int StrsLengthMin=strs[0].size();
        int Strsize=strs.size();
        for(int i=1;i<Strsize;i++){//寻找最短字符串
            if(strs[i].size()<StrsLengthMin){
                StrsLengthMin=strs[i].size();
            }   
        }
        int j=1;//取字符串长度
        for(j=1;j<=StrsLengthMin;j++){
            for(int i=0;i<Strsize-1;i++){
                if(strs[i].substr(0,j)!=strs[i+1].substr(0,j)){
                    goto end;
                }
            }
        }
        end:
            return strs[0].substr(0,j-1);
    }
};