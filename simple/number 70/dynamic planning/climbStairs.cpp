int factorial(int n);
class Solution {
public:
    int climbStairs(int n) {
        int p=0,q=1,sum=1;//p为0级台阶，q为1级台阶，sum先存了一级台阶
        for(int i=2;i<=n;i++){
            p=q;//p存f(x-2)
            q=sum;//q存f(x-1)
            sum=p+q;//sum存f(x)
        }
        return sum;
    }
};