//逆向双指针，先判断数组越界情况，再比较两个数组当前元素大小，较大者放在nums1末尾
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m+n-1;//nums1尾元素
        int p1=m-1,p2=n-1;
        while(p1>=0||p2>=0){
            int cur=0;
            if(p1==-1){
                cur=nums2[p2--];
            }else if(p2==-1){
                cur=nums1[p1--];
            }else if(nums1[p1]>nums2[p2]){
                cur=nums1[p1--];
            }else{
                cur=nums2[p2--];
            }
            nums1[i--]=cur;
        }

    }
};