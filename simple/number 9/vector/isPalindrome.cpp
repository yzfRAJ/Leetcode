class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if(x<0) return false;
        if(x>=0&&x<=9) return true;
        while(x!=0)
        {
            arr.push_back(x%10);
            x/=10;
        }
        int num=0;
        vector<int>::iterator it=arr.begin();
        for(;it<arr.begin()+arr.size()/2;it++)
        {   
            num+=*it==*(arr.begin() + (arr.size()- (it - arr.begin()+1)));//迭代器只允许it+/-n，不允许n+/-it，两个迭代器相减得到的结果是距离
        }
        if(num==arr.size()/2) return true;
        else return false;
    }    