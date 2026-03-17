//先比较后面的元素用栈，如果后面元素是右括号，且栈顶元素是对应的左括号，则弹出栈顶元素，否则将当前元素入栈，最后判断栈是否为空即可。
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> str;
        str[')']='(';
        str['}']='{';
        str[']']='[';
        stack<char> ss;
        for(auto x:s){
            if(!ss.empty()&&str.count(x)&&str[x]==ss.top()){
                ss.pop();
            }else ss.push(x);
        }
        return ss.empty();
    }
};