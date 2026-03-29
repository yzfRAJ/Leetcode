//用切线去逼近，直到两次迭代的结果足够接近为止
class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        double C=x,x0=x;
        while(1){
            double xi=0.5*(x0+C/x0);
            if(fabs(x0-xi)<1e-7){
                break;
            }
            x0=xi;
        }
        return int(x0);
    }
};