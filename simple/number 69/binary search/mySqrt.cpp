class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        long num=1,pow=0,p=0;
        while(num<x){//求幂指数
            num=num*2;
            pow++;
        }
        num=1;
        while(p<(pow-1)/2){//求开方后的幂指数
            num=num*2;
            p++;
        }
        int left=num,right=num*3;
        while(left<=right){//二分查找
            long mid=left+(right-left)/2;
            if(mid*mid<x){
                left=mid+1;
            }else if(mid*mid>x){
                right=mid-1;
            }else return mid;
        }
        return right;
    }
};



//直接二分查找
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int left=1,right=x/2;
        while(left<=right){
            long mid=(left+right)/2;
            if(mid*mid<x) left=mid+1;
            else if(mid*mid>x) right=mid-1;
            else return mid;
        }
        return right;
    }
};