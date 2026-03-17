class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> Rot={//char是键，int是值
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int num=0;
        int i=0;
        for(i=0;i<s.size()-1;i++){
            if(Rot[s[i]]>=Rot[s[i+1]]){
                num+=Rot[s[i]];
            }
            else{
                num+=Rot[s[i+1]]-Rot[s[i]];
                i++;
            }
        }
        if(i!=s.size())
        {
            num+=Rot[s[i]];
        }
        return num;
    }
};