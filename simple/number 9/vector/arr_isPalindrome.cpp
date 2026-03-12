//用下标访问vector的元素，判断是否是回文数
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if(x<0) return false;
        if(x>=0&&x<=9) return true;
        while(x!=0){
            arr.push_back(x%10);
            x/=10;
        }
        int num=0;
        for(int j=0;j<arr.size()/2;j++)
        {
            num+=arr[j]==arr[arr.size()-j-1];
        }
        if(num==(arr.size()/2)) return true;
        return false;
    }
};