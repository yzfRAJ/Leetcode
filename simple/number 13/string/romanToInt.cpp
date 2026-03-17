//注意c++幂运算不是用^，而是pow函数，
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        string b="IVXLCDM";
        string c="IVIXXLXCCDCM";
        for(int i=0;i<6;i++){
            if(s.find(c.substr(i*2,2))!=-1){//找不到返回-1
                if(i%2==0){
                    num+=4*pow(10,i/2);//幂运算函数
                }
                else num+=9*pow(10,i/2);
                s.erase(s.find(c.substr(i*2,2)),2);//substr从字符串中提取子字符串
            }
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<b.size();j++){
                if(s[i]==b[j]){
                    if(j%2==0){
                        num+=pow(10,j/2);
                    }
                    else num+=5*pow(10,j/2);
                }
            }
        }
        return num;
    }
};