class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        string b="IVXLCDM";
        char c[][3]={"IV","IX","XL","XC","CD","CM"};
        for(int i=0;i<6;i++){
            if(s.find(c[i])!=-1){
                if(i%2==0){
                    num+=4*pow(10,i/2);
                }
                else num+=9*pow(10,i/2);
                s.erase(s.find(c[i]),2);
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