//反向遍历判断进位
class Solution {
public:
    string addBinary(string a, string b) {
        int a_len=a.size()-1;
        int b_len=b.size()-1;
        if(a_len>b_len) b.insert(0,a_len-b_len,'0');
        else a.insert(0,b_len-a_len,'0');//高位补零
        int n=a_len>b_len?a_len:b_len;
        string c;
        c.insert(0,n+1,'0');//初始化为0
        int flag = 0;
        while(n>=0){
            if(a[n]=='1'&&b[n]=='1'&&flag==0){
                flag=1;
            }else if(a[n]=='1'&&b[n]=='1'&&flag==1){
                c[n]='1';
            }else if(a[n]=='0'&&b[n]=='0'&&flag==1){
                c[n]='1';
                flag=0;
            }else if((a[n]!='0'||b[n]!='0')&&flag==0)
                c[n]='1';
            n--;
        }
        if(flag==1){//判断第一位
            c.insert(0,1,'1');
        }
        return c;
    }
};