class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int num=n/2;//最大2的个数
        int sum=0;//记录累加值
        while(num>=2){
            int m=num;
            long fa=1;
            for(int j=1;j<=min(num,n-num*2);j++){//排列组合
                fa*=n-m++;
                fa/=j;
            }
            sum+=fa;
            num--;
        }
        return n+sum;
    }
};