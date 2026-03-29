class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.size() - 1;
        int b_len = b.size() - 1;
        if (a_len > b_len)
            b.insert(0, a_len - b_len, '0');//高位补零
        else
            a.insert(0, b_len - a_len, '0');
        int n = a_len > b_len ? a_len : b_len;
        string c;
        int carry = 0,sum=0;
        while (n >= 0) {
            sum+=(a[n]-'0')+(b[n]-'0')+carry;//ASCLL简化判断
            c=to_string(sum%2)+c;
            sum=0;
            if((a[n]-'0')+(b[n]-'0')+carry<2)
                carry=0;
            else carry=1;
            n--;
        }
        if (carry == 1) {
            c='1'+c;
        }
        return c;
    }
};